from sklearn.cluster import KMeans
import numpy as np
X = np.array([[1, 2], [1, 4], [1, 0], [10, 2], [10, 4], [1, 3], [5, 6], [4, 0], [9, 4]])
kmeans = KMeans(n_clusters=5, random_state=0).fit(X)
print("Her bir elemanın kümesi: ",kmeans.labels_)

print("Kümelerin merkezleri: ",kmeans.cluster_centers_)

print("Test verilerinin kümeleri: ",kmeans.predict([[0, 0], [12, 3], [7, 8]]))
