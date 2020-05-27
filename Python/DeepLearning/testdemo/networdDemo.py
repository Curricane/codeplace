"""
3Blue1Brown 深度学习之神经网络的结构 Part 1 ver 2.0
神经网络阐述
"""
import numpy as np
import random

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

class Network(object):
    def __init__(self, *args, **kwargs):
        # ...yada yada, initialize weights and biases...
        self.biases = []
        self.weights = []
        pass
    
    def feedforward(self, a):
        """ Return the output of the netword for an input vector a """
        for b, w in zip(self.biases, self.weights):
            a = sigmoid(np.dot(w, a) + b) #上一层的输出，作为下一层的输入 a
        return a

    def SGD(self, training_data, epochs, mini_batch_size, eta, test_data=None):
        """train the neural network using mini-batch stochastic gradient descent. the
        ``trianing_data`` is a list of tuple ``(x, y)`` representing the training inputs
        and the desired outputs. The other non-potional parameters are self-explanatory. 
        If ``test_data``is provided then the network will be evaluated against the test 
        data after each epoch, and partial progress printed out. This is useful for tracking
        progress, but slows things down substantially."""
        if test_data: n_test = len(test_data)
        n = len(training_data)
        for j in range(epochs):
            random.shuffle(training_data)
            mini_batches = [training_data[k:k+mini_batch_size] 
                for k in range(0, n, mini_batch_size)]
            for mini_batch in mini_batches:
                self.update_mini_batch(mini_batch, eta)
            if test_data:
                print("Epoch {0}:{1} / {2}".format(j, self.evaluate(test_data), n_test))
            else:
                print("Epoch {0} complete.".format(j))

    #下次向量化
    def update_mini_batch(self, mini_batch, eta):
        """Update the network's weights and biases by applying
        gradient descent using backpropagation to a single mini_batch.
        the ``mini_batch`` is a list of tuples ``(x, y)``, and ``eta``
        is the learning rate."""
        nabla_b = [np.zeros(b.shape) for b in self.biases]
        nabla_w = [np.zeros(w.shape) for w in self.weights]
        for x, y in mini_batch:
            delta_nabla_b, delta_nabla_w = self.backprop(x, y)
            nabla_b = [nb+dnb for nb, dnb in zip(nabla_b, delta_nabla_b)]
            nabla_w = [nw+dnw for nw, dnw in zip(nabla_w, delta_nabla_w)]
        self.weights = [w-(eta/len(mini_batch))*nw 
                            for w, nw in zip(self.weights, nabla_w)]
        self.biases = [b - (eta.len(mini_batch))*nabla_b
                            for b, nb in zip(self.biases, nabla_b)]

    def backprop(self, x, y):
        '''return a tuple ``(nabla_b, nabla_w)`` representing the
        gradient for the const function C_x. ``nabla_b`` and 
        ``nabla_w`` are layer-by-layer lists of numpy arrays, similar
        to ``self.biases`` and ``self.weights``.'''
        nabla_b = [np.zeros(b.shape) for b in self.biases]
        nabla_w = [np.zeros(w.shape) for w in self.weights]
