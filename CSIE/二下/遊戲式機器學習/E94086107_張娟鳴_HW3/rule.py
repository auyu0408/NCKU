"""
The template of the script for playing the game in the ml mode
"""

class MLPlay:
    def __init__(self):
        """
        Constructor
        """
        self.flag = 0
        pass

    def update(self, scene_info):
        """
        Generate the command according to the received scene information
        """
        if scene_info["status"] == "GAME_OVER":
            return "RESET"

        snake_head = scene_info["snake_head"]
        if len(scene_info["snake_body"]) > 150:
            return "NONE"
        if snake_head[1] == 0:
            if snake_head[0] == 0:
                return "DOWN"
            else:
                return "LEFT"
        if snake_head[1] == 290:
            if snake_head[0] == 290:
                return "UP"
            if self.flag == 0:
                self.flag = 1
                return "RIGHT"
            else:
                self.flag = 0
                return "UP"
        if snake_head[1]==10:
            if snake_head[0] == 290:
                return "UP"
            if self.flag == 0:
                self.flag = 1
                return "RIGHT"
            else:
                self.flag = 0
                return "DOWN"
        else:
            return "NONE"
    def reset(self):
        """
        Reset the status if needed
        """
        self.flag = 0
        pass
