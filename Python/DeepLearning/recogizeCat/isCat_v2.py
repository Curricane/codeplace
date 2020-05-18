import numpy as np 
from  lrUtils import load_dataset

def sigmoid(x):
    return 1 / (1+np.exp(-x))

def deriv_sigmoid(x):
    a = sigmoid(x)
    return a * (1 - a)

def loss_func(a, y):
    return -y * np.log(a) - (1 - y) * np.log(1 - a)

def deriv_loss_func(a, y):
    return -y / a + (1 - y) / (1 - a)

class Network:
    def __init__(self, weights, biases):
        assert(len(weights) == len(biases))
        
        for i in range(len(weights)):
            assert(weights[i].shape[0] == biases[i].shape[0])
        self.layers = len(weights) # 神经网络层数，不计输入层，第一隐层为第0层
        self.weights = weights
        self.biases = biases

    def feedforword(self, a0):
        assert( a0.shape[0] == self.weights[0].shape[1])
        A = [] #输入为 a0
        A.append(a0)
        Z = []
        Z.append(np.array(0).reshape(1,1)) # 仅用来填充
        l = 0
        for w, b in zip(self.weights, self.biases):
            z = np.dot(w, A[l]).reshape(w.shape[0], A[l].shape[1]) + b
            a = sigmoid(z)
            A.append(a)
            Z.append(z)
            l += 1
        return (Z, A) 

    def forward(self, a0):
        for b, w in zip(self.biases, self.weights):
            a0 = sigmoid(np.dot(w, a0) + b) #上一层的输出，作为下一层的输入 a
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
            dZl = dA[l] * deriv_sigmoid(Z[l])
            dZ[l] = dZl
            dWl =  np.dot(dZ[l], A[l-1].T) / m
            dW[l] = dWl
            dBl = np.sum(dZ[l], axis=1, keepdims=True) / m
            dB[l] = dBl
            if l - 1 > 0:
                dA[l-1] = np.dot(self.weights[l-1].T, dZ[l])
        return dW[1:], dB[1:]

    def train(self, training_data_x, training_data_y, test_data_x, test_data_y, lRate = 0.001, epochs = 4000 ):
        costs = []
        for epoch in range(epochs):
            dW, dB = self.backprop(training_data_x, training_data_y)
            assert(len(dW) == len(self.weights) and len(dB) == len(self.biases))
            for l in range(len(dW)):
                self.weights[l] -= lRate * dW[l]
                self.biases[l] -= lRate * dB[l]

            if epoch % 100 == 0:
                # Z, A = self.feedforword(test_data_x)
                # cost = self.cost_func(A[self.layers], test_data_y)
                Z, A = self.feedforword(training_data_x)
                cost = self.cost_func(A[self.layers], training_data_y)
                costs.append(cost)
                print("{0} cost is: {1}".format(epoch, cost))
    
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
    
if __name__ == '__main__':
    train_set_x_orig, train_set_y_orig, test_set_x_orig, test_set_y_orig, classes = load_dataset()
    train_set_x = train_set_x_orig.reshape(train_set_x_orig.shape[0], -1).T
    test_set_x = test_set_x_orig.reshape(test_set_x_orig.shape[0], -1).T
    train_set_x = train_set_x / 255
    test_set_x = test_set_x / 255

    n_input = train_set_x.shape[0]
    
    w1 = np.random.rand(16, n_input) * 0.001
    w2 = np.random.rand(8, 16) * 0.001
    w3 = np.random.rand(4, 8) * 0.001
    w4 = np.random.rand(1, 4) * 0.001
    weights = [w1, w2, w3, w4]

    b1 = np.random.rand(16, 1) * 0.001
    b2 = np.random.rand(8, 1) * 0.001
    b3 = np.random.rand(4, 1) * 0.001
    b4 = np.random.rand(1, 1) * 0.001
    biases = [b1, b2, b3, b4]
    # weights = [np.random.rand(1, n_input) * 0.001]
    # biases = [np.random.rand(1,1) * 0.001]
    isCatNet = Network(weights, biases)
    isCatNet.train(train_set_x, train_set_y_orig, test_set_x, test_set_y_orig)
    y_pred_train = isCatNet.predict(train_set_x)
    acc = isCatNet.getAcc(y_pred_train, train_set_y_orig)
    print("train acc: ", acc) 
    
    y_pred_test = isCatNet.predict(test_set_x)
    acc = isCatNet.getAcc(y_pred_test, test_set_y_orig)
    print("test acc: ", acc) 



        

                
        