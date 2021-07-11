import pickle
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn import metrics
from sklearn import tree
from sklearn.metrics import classification_report, confusion_matrix

file = open("/home/auyu/E94086107/MLGame/games/snake/log/40.pickle","rb")
data = pickle.load(file)
file.close()

game_info = data["ml"]["scene_info"]
game_command = data["ml"]["command"]

g = game_info[1]

feature = np.array([g["snake_head"][0], g["snake_head"][1]])

for i in range (2, len(game_info)-1):
	g = game_info[i]
	if len(g["snake_body"]) >150:
		s = 0
	else:
		feature = np.vstack((feature, [g["snake_head"][0],g["snake_head"][1]]))

c = game_command[1]
if c == "NONE":
	ans = np.array([0])
elif c == "UP":
	ans = np.array([1])
elif c == "DOWN":
	ans = np.array([-1])
elif c == "LEFT":
	ans = np.array([2])
else:
	ans = np.array([-2])

for i in range(2,len(feature)+1):
	c = game_command[i]
	if c == "NONE":
		ans = np.vstack((ans,0))
	elif c == "UP":
		ans = np.vstack((ans,1))
	elif c == "DOWN":
		ans = np.vstack((ans,-1))
	elif c == "LEFT":
		ans = np.vstack((ans,2))
	else:
		ans = np.vstack((ans,-2))

print(feature.shape)
print(ans.shape)

x_train, x_test, y_train, y_test = train_test_split(feature, ans, test_size=0.3, random_state = 1)

grid = tree.DecisionTreeClassifier()
grid = grid.fit(x_train, y_train)

predicted = grid.predict(x_test)

file = open("model.pickle", "wb")
pickle.dump(grid, file)
file.close()

print("Accuracy score (validation): {0:.3f}".format(grid.score(x_test, y_test)))
print("Confusion Matrix for Decision Tree:")
print(confusion_matrix(y_test, predicted))
print()
print("Classification Report for Decision Tree")
print(classification_report(y_test, predicted))
