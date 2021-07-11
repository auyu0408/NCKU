import pickle
import numpy as np

from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import GridSearchCV
from sklearn.model_selection import StratifiedShuffleSplit

file = open("/home/auyu/E94086107/MLGame/games/pingpong/log_1/data(1).pickle","rb")
data = pickle.load(file)
file.close()

game_info = data["ml_1P"]["scene_info"]
game_command = data["ml_1P"]["command"]

for i in range (2,77):
	path = "/home/auyu/E94086107/MLGame/games/pingpong/log_1/data("+str(i)+").pickle"
	file = open(path,"rb")
	data = pickle.load(file)
	game_info = game_info + data["ml_1P"]["scene_info"]
	game_command = game_command + data["ml_1P"]["command"]
	file.close

g = game_info[1]

feature = np.array([g["ball"][0], g["ball"][1], g["ball_speed"][0], g["ball_speed"][1], g["platform_1P"][0]])
print(feature)
print(game_command[1])
if game_command[1] == "NONE":
	game_command[1] = 0
elif game_command[1] == "MOVE_LEFT":
	game_command[1] = 1
else:
	game_command[1] = 2

for i in range (2, len(game_info)-1):
	g = game_info[i]
	feature = np.vstack((feature, [g["ball"][0], g["ball"][1], g["ball_speed"][0], g["ball_speed"][1], g["platform_1P"][0]]))
	if game_command[i] == "NONE":
		game_command[i] = 0
	elif game_command[i] == "MOVE_LEFT":
		game_command[i] = 1
	else:
		game_command[i] = 2

answer = np.array(game_command[1:-1])
print(feature.shape)
print(answer.shape)

x_train, x_test, y_train, y_test = train_test_split(feature, answer, test_size=0.3, random_state = 1)

#參數區間
param_grid = {'n_neighbors':[1, 2, 3]}
#交叉驗證 
cv = StratifiedShuffleSplit(n_splits=2, test_size=0.3, random_state=12)
grid = GridSearchCV(KNeighborsClassifier(), param_grid, cv=cv, verbose=10, n_jobs=-1) #n_jobs為平行運算的數量
grid.fit(x_train, y_train)
grid_predictions = grid.predict(x_test)


predicted = grid.predict(x_test)

file = open("model_knn_505_nb.pickle", "wb")
pickle.dump(grid, file)
file.close()

print("Accuracy score (validation): {0:.3f}".format(grid.score(x_test, y_test)))
print("Confusion Matrix for Decision Tree:")
print(confusion_matrix(y_test, predicted))
print()
print("Classification Report for Decision Tree")
print(classification_report(y_test, predicted))
