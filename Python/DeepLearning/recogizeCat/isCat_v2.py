import numpy as np 
from  lrUtils import load_dataset
import matplotlib.pyplot as plt
import h5py

def sigmoid(x):
    return 1 / (1+np.exp(-x))

def deriv_sigmoid(x):
    a = sigmoid(x)
    return a * (1 - a)

def relu(x):
    return np.maximum(x, 0).reshape(x.shape[0], x.shape[1])

def deriv_relu(x):
    x = relu(x)
    x[x>0] = 1
    return x


def loss_func(a, y):
    return -y * np.log(a) - (1 - y) * np.log(1 - a)

def deriv_loss_func(a, y):
    return -y / a + (1 - y) / (1 - a)

class Network:
    def __init__(self, nodes, actives):
        assert(len(nodes) - 1 == len(actives))
        self.layers = len(nodes) - 1
        weights = []
        biases = []
        for l in range(1, self.layers + 1):
            w1 = np.random.rand(nodes[l], nodes[l-1]) * 0.001
            b1 = np.random.rand(nodes[l], 1) * 0.001
            weights.append(w1)
            biases.append(b1)
        self.weights = weights
        self.biases = biases
        self.actives = actives # 用于存放每一层的激活函数 和其导数(active_func, deriv_func)

        

    def feedforword(self, a0):
        assert( a0.shape[0] == self.weights[0].shape[1])
        A = [] #输入为 a0
        A.append(a0)
        Z = []
        Z.append(np.array(0).reshape(1,1)) # 仅用来填充
        l = 0
        for w, b , active in zip(self.weights, self.biases, self.actives):
            z = np.dot(w, A[l]).reshape(w.shape[0], A[l].shape[1]) + b
            # a = sigmoid(z)
            a = active[0](z)
            A.append(a)
            Z.append(z)
            l += 1
        return (Z, A) 

    def forward(self, a0):
        for w, b , active in zip(self.weights, self.biases, self.actives):
            a0 = active[0](np.dot(w, a0) + b) #上一层的输出，作为下一层的输入 a
        return a0

    def cost_func(self, a, y):
        assert(a.shape == y.shape)
        m = a.shape[1]
        return np.sum(loss_func(a, y), axis=1, keepdims=True) / m

    def deriv_cost_func(self, a, y):
        return deriv_loss_func(a, y)

    def backprop(self, x, y):
        Z, A = self.feedforword(x)
        m = A[0].shape[1]
        dA = [0] * (self.layers + 1)
        dZ = [0] * (self.layers + 1)
        dW = [0] * (self.layers + 1)
        dB = [0] * (self.layers + 1)
        dal = self.deriv_cost_func(A[self.layers], y)
        dA[self.layers] = dal
        for l in range(self.layers, 0, -1):
            #dZl = dA[l] * deriv_sigmoid(Z[l])
            dZl = dA[l] * self.actives[l-1][1](Z[l])
            dZ[l] = dZl
            dWl =  np.dot(dZ[l], A[l-1].T) / m
            dW[l] = dWl
            dBl = np.sum(dZ[l], axis=1, keepdims=True) / m
            dB[l] = dBl
            if l - 1 > 0:
                dA[l-1] = np.dot(self.weights[l-1].T, dZ[l])
        return dW[1:], dB[1:]

    def train(self, training_data_x, training_data_y, test_data_x, test_data_y, lRate = 0.01, epochs = 10000 ):
        costs_test = []
        costs = []
        for epoch in range(epochs):
            dW, dB = self.backprop(training_data_x, training_data_y)
            assert(len(dW) == len(self.weights) and len(dB) == len(self.biases))
            for l in range(len(dW)):
                self.weights[l] -= lRate * dW[l]
                self.biases[l] -= lRate * dB[l]

            if epoch % 100 == 0:
                Z_test, A_test = self.feedforword(test_data_x)
                cost_test = self.cost_func(A_test[self.layers], test_data_y)
                Z, A = self.feedforword(training_data_x)
                cost_train = self.cost_func(A[self.layers], training_data_y)
                costs.append(cost_train)
                costs_test.append(cost_test)
                print("{0} test cost is: {1} trian cost is {2}".format(epoch, cost_test, cost_train))
        return (costs_test, costs)
    
    def predict(self, x):
        m = x.shape[1]
        y_pred = np.zeros((1, m))
        A = self.forward(x)
        for i in range(A.shape[1]):
            y_pred[0, i] = 1 if A[0,i] > 0.5 else 0
        return y_pred

    def getAcc(self, y_pred, y_true):
        assert(y_pred.shape == y_true.shape)
        return 1 - np.mean(np.abs(y_pred - y_true))

    def saveParams2H5(self, path='./model.h5'):
        f = h5py.File(path, 'w')
        f.create_dataset('layers', data=self.layers)
        for i in range(self.layers):
            key = 'w' + str(i)
            f.create_dataset(key, data=self.weights[i])
            key = 'b' + str(i)
            dset = f.create_dataset(key, data=self.biases[i])
        actives = np.zeros((1, self.layers))
        i = 0
        for x in self.actives:
            if str(x[0]) == 'relu':
                actives[0, i] = 1
            i += 1
        f.create_dataset('actives', data=actives)

    """
    # 取出还有问题
    def initFromH5(self, path='./model.h5'):
        f = h5py.File(path, 'r')
        self.layers = f['layers'][0, 0]
        i = 0
        for x in range(self.layers):
            key1 = 'w' + str(x)
            key2 = 'b' + str(x)
            self.weights[x] = f[key1]
            self.biases[x] = f[key2]
        actives = f['actives']
        for x in actives:
            if x == 0:
                self.actives[i] = (sigmoid, deriv_sigmoid)
            elif x == 1:
                self.actives[i] = (relu, deriv_relu)
            i += 1
    """
    
if __name__ == '__main__':
    train_set_x_orig, train_set_y_orig, test_set_x_orig, test_set_y_orig, classes = load_dataset()
    train_set_x = train_set_x_orig.reshape(train_set_x_orig.shape[0], -1).T
    test_set_x = test_set_x_orig.reshape(test_set_x_orig.shape[0], -1).T
    train_set_x = train_set_x / 255
    test_set_x = test_set_x / 255

    n_input = train_set_x.shape[0]
    
    nodes = [n_input, 1]
    actives = [(relu, deriv_relu),(sigmoid, deriv_sigmoid)]
    isCatNet = Network(nodes, actives)
    costs_test, costs_trian = isCatNet.train(train_set_x, train_set_y_orig, test_set_x, test_set_y_orig, epochs=60000)
    #isCatNet.saveParams2H5()
    y_pred_train = isCatNet.predict(train_set_x)
    acc = isCatNet.getAcc(y_pred_train, train_set_y_orig)
    print("train acc: ", acc) 
    
    y_pred_test = isCatNet.predict(test_set_x)
    acc = isCatNet.getAcc(y_pred_test, test_set_y_orig)
    print("test acc: ", acc) 

    costs_test = np.squeeze(costs_test)
    costs_trian = np.squeeze(costs_trian)

    fig, ax = plt.subplots()
    ax.plot(costs_test, label="test")
    ax.plot(costs_trian, label="train")
    ax.set_xlabel('epoches / hundreds')
    ax.set_ylabel('costs')
    ax.legend()
    fig.show()




        

                
        