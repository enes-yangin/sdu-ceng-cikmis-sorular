from sklearn.datasets import load_iris
from sklearn import tree
X, y = load_iris(return_X_y=True)
"""
clf = tree.ExtraTreeClassifier() #sınıflandırma için
"""
clf = tree.DecisionTreeClassifier() #c4.5

clf = clf.fit(X, y)
tree.plot_tree(clf) 
