import numpy as np
from  lrUtils import load_dataset
import matplotlib.pyplot as plt
import time

# 激活函数sigmoid
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# 交叉熵损失函数
def loss_func(a, y):
    return -y * np.log(a) - (1 - y) * np.log(1 - a)

class IsCatNet:
    def __init__ (self, weight, biases):
        assert(weight.shape[0] == 1)
        assert(biases.shape == (1,1))
        self.weights = weight
        self.biases = biases
        self.n_x = self.weights.shape[1]


    def feedforward(self, x):
        #for w, b in zip(self.weights, self.biases):
        assert(self.n_x == x.shape[0])
        n_samples = x.shape[1]
        z = np.dot(self.weights, x).reshape(1, n_samples) + self.biases
        a = sigmoid(z)
        return a

    def cost_func(self, a, y):
        m = a.shape[1]
        assert( m != 0)
        return np.sum(loss_func(a, y), axis= 1) / m


    def backprop(self, x, y):
        assert(self.n_x == x.shape[0])
        n_samples = x.shape[1]
        z = np.dot(self.weights, x).reshape(1, n_samples) + self.biases
        a = sigmoid(z)

        dz = a - y
        m = y.shape[1]
        assert(n_samples == m)

        dw = np.dot(dz, x.T) / m
        db = np.sum(a - y, axis=1, keepdims=True) / m
        assert(dw.shape[0] == self.weights.shape[0] and dw.shape[1] == self.weights.shape[1])
        assert(db.shape[0] == self.biases.shape[0] and db.shape[1] == self.biases.shape[1])
        return dw, db

    def train(self, training_data_x, training_data_y, test_data_x, test_data_y, lRate = 0.01, epochs = 10000 ):
        costs = []
        for epoch in range(epochs):
            dw, db = self.backprop(training_data_x, training_data_y)

            self.weights -= lRate * dw 
            self.biases -= lRate * db

            if epoch % 100 == 0:
                t_a = self.feedforward(test_data_x)
                cost = self.cost_func(t_a, test_data_y)
                # t_a = self.feedforward(training_data_x)
                # cost = self.cost_func(t_a, training_data_y)
                costs.append(cost)
                print("{0} cost is: {1}".format(epoch, cost))
        
        return costs

    def predict(self, x):
        m = x.shape[1]
        y_pred = np.zeros((1, m))
        A = self.feedforward(x)
        for i in range(A.shape[1]):
            y_pred[0, i] = 1 if A[0,i] > 0.5 else 0
        return y_pred

    def getAcc(self, y_pred, y_true):
        assert(y_pred.shape == y_true.shape)
        return 1 - np.mean(np.abs(y_pred - y_true))

def trainModel(train_set_x, train_set_y_orig, test_set_x, test_set_y_orig):
    
    dim = train_set_x.shape[0]
    weights = np.random.rand(1, dim) * 0.001 #需要成0.0001，不然开始计算会溢出
    biases = np.random.rand(1,1) * 0.001
    lRate = 0.01
    isCat = IsCatNet(weights, biases)
    costs = isCat.train(train_set_x, train_set_y_orig, test_set_x, test_set_y_orig, epochs=2000)
    #costs_squeeze = np.squeeze(costs)
    
    y_pred = isCat.predict(test_set_x)
    acc = isCat.getAcc(y_pred, test_set_y_orig)
    print("acc: ", acc) 
    
    with open('model.txt', 'w') as f:
        f.write(",".join([str(x) for x in isCat.weights[0]]))
        f.write('\n')
        f.write(str(isCat.biases[0,0]))
    return costs

def showcost(costs, lRate):
    fig, axe = plt.subplots()
    axe.plot(costs, label=str(lRate))
    axe.set_xlabel('epochs (per hundreds)')
    axe.set_ylabel('cost')
    axe.set_title('costs')
    axe.legend()
    fig.show()
    
    
    

def predict(test_set_x, test_set_y_orig):
    weights_get = []
    biases_get = 0.0
    with open('model.txt', 'r') as f:
        str_weight = f.readline().split(',')
        for x in str_weight:
            weights_get.append(float(x))
            
        str_biaes = f.readline()
        biases = float(str_biaes)

    weights = np.array(weights_get).reshape(1, len(weights_get))
    biases = np.array(biases_get).reshape(1, 1)
    #plt.imshow(test_set_x_orig[0])
    isCat = IsCatNet(weights, biases)
    y_pred = isCat.predict(test_set_x)
    
    acc = isCat.getAcc(y_pred, test_set_y_orig)
    print("acc: ", acc)
    # for x in range(test_set_x.shape[1]):
    #     # 这样做并不能打印出图片
    #     #plt.imshow(test_set_x_orig[x])
    #     time.sleep(2)
    #     result = iscat.predict(test_set_x[:,x].reshape(-1, 1))
    #     print(x, result)

if __name__ == '__main__':
    train_set_x_orig, train_set_y_orig, test_set_x_orig, test_set_y_orig, classes = load_dataset()
    train_set_x = train_set_x_orig.reshape(train_set_x_orig.shape[0], -1).T
    test_set_x = test_set_x_orig.reshape(test_set_x_orig.shape[0], -1).T
    train_set_x = train_set_x / 255
    test_set_x = test_set_x / 255

    costs = trainModel(train_set_x, train_set_y_orig, test_set_x, test_set_y_orig)
    #showcost(costs, 0.01)
    predict(test_set_x, test_set_y_orig)
    
    
    



    

    
    