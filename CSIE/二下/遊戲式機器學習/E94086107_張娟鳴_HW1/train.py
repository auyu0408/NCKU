import pickle
import numpy as np
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import GridSearchCV
from sklearn.model_selection import StratifiedShuffleSplit

file = open("/home/auyu/E94086107/MLGame/games/arkanoid/log/n3(1).pickle","rb")
data = pickle.load(file)
file.close()

game_info = data['ml']['scene_info']
game_command = data['ml']['command']

for i in range(2, 132):
    path = "/home/auyu/E94086107/MLGame/games/arkanoid/log/n3("+str(i)+").pickle"
    file = open(path, "rb")
    data = pickle.load(file)
    game_info = game_info + data['ml']['scene_info']
    game_command = game_command + data['ml']['command']
    file.close()
    
print(len(game_info))
print(len(game_command))

#特徵整理
g = game_info[1]

feature = np.array([g['ball'][0], g['ball'][1], g['platform'][0],g['ball'][0]-75,g['ball'][1]-400])
print(feature)

print(game_command[1])
game_command[1] = 0

for i in range(2, len(game_info) - 1):
    f = game_info[i-1]
    g = game_info[i]
    feature = np.vstack((feature, [g['ball'][0], g['ball'][1], g['platform'][0],g['ball'][0]-f['ball'][0],g['ball'][1]-f['ball'][1]]))
    if game_command[i] == "NONE": game_command[i] = 0
    elif game_command[i] == "MOVE_LEFT": game_command[i] = 1
    else: game_command[i] = 2
    
answer = np.array(game_command[1:-1])

print(feature)
print(feature.shape)
print(answer)
print(answer.shape)

#資料劃分
x_train, x_test, y_train, y_test = train_test_split(feature, answer, test_size=0.3, random_state=9)
#參數區間
param_grid = {'n_neighbors':[1, 2, 3]}
#交叉驗證 
cv = StratifiedShuffleSplit(n_splits=2, test_size=0.3, random_state=12)
grid = GridSearchCV(KNeighborsClassifier(), param_grid, cv=cv, verbose=10, n_jobs=-1) #n_jobs為平行運算的數量
grid.fit(x_train, y_train)
grid_predictions = grid.predict(x_test)

#儲存
file = open('model.pickle', 'wb')
pickle.dump(grid, file)
file.close()

#最佳參數
print(grid.best_params_)
#預測結果
#print(grid_predictions)
#混淆矩陣
print(confusion_matrix(y_test, grid_predictions))
#分類結果
print(classification_report(y_test, grid_predictions))
