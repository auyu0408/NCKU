import pickle
import os.path
"""
The template of the script for playing the game in the ml mode
"""

class MLPlay:
    def __init__(self):
        """
        Constructor
        """
        filename = 'model.pickle'
        filepath = os.path.join(os.path.dirname(__file__), filename)
        self.model = pickle.load(open(filepath, 'rb'))

    def update(self, scene_info):
        """
        Generate the command according to the received scene information
        """
        if scene_info["status"] == "GAME_OVER":
            return "RESET	"

        snake_head = scene_info["snake_head"]
        if len(scene_info["snake_body"]) > 850:
            return "NONE"
        else:
            hx = snake_head[0]
            hy = snake_head[1]
            ans = self.model.predict([[hx, hy]])
            if ans == -2:
                command = "RIGHT"
            elif ans == -1:
                command = "DOWN"
            elif ans == 0:
                command = "NONE"
            elif ans == 1:
                command = "UP"
            else:
                command = "LEFT"
            return command

    def reset(self):
        """
        Reset the status if needed
        """
        pass
