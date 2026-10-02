#Import scikit-learn dataset library
from sklearn import datasets

#Load dataset
iris = datasets.load_iris()
"""
# print the names of the 4 features
print("Features: ", iris.feature_names)

# print the label type of iris(class_0, class_1, class_2)
print("Labels: ", iris.target_names)

# print data(feature)shape
print(iris.data.shape)

# print data features
print(iris.data[0:])

# print the wine labels (0:Class_0, 1:class_2, 2:class_2)
print(iris.target)
"""
# Import train_test_split function
from sklearn.model_selection import train_test_split

# Split dataset into training set and test set
X_train, X_test, y_train, y_test = train_test_split(iris.data, iris.target, test_size=0.3,random_state=109) # 70% training and 30% test

#Import Gaussian Naive Bayes model
from sklearn.naive_bayes import GaussianNB

#Create a Gaussian Classifier
gnb = GaussianNB()

#Train the model using the training sets
gnb.fit(X_train, y_train)

print(X_test)
#Predict the response for test dataset
y_pred = gnb.predict(X_test)

print("Olması gereken: ", y_test)
print("Tahmin edilen: ", y_pred)
#Import scikit-learn metrics module for accuracy calculation
from sklearn import metrics

# Model Accuracy, how often is the classifier correct?
print("Accuracy:",metrics.accuracy_score(y_test, y_pred))
