import numpy as np 
import h5py

def load_dataset():
    train_dataset = h5py.File('/Users/boolee/Desktop/workplace/study/codeplace/Python/DeepLearning/recogizeCat/datasets/train_catvnoncat.h5', 'r')

    #原始的输入x 和 原始的输出y
    train_set_x_orig = np.array(train_dataset["train_set_x"][:])
    train_set_y_orig = np.array(train_dataset["train_set_y"][:])
    test_dataset = h5py.File('/Users/boolee/Desktop/workplace/study/codeplace/Python/DeepLearning/recogizeCat/datasets/test_catvnoncat.h5', "r")
    test_set_x_orig = np.array(test_dataset["test_set_x"][:]) # your test set features
    test_set_y_orig = np.array(test_dataset["test_set_y"][:]) # your test set labels

    classes = np.array(test_dataset["list_classes"][:]) # the list of classes
    
    train_set_y_orig = train_set_y_orig.reshape((1, train_set_y_orig.shape[0]))
    test_set_y_orig = test_set_y_orig.reshape((1, test_set_y_orig.shape[0]))
    
    return train_set_x_orig, train_set_y_orig, test_set_x_orig, test_set_y_orig, classes
