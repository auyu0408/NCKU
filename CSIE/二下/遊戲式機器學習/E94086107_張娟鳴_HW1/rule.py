"""
The template of the main script of the machine learning process
"""
import random
class MLPlay:
    def __init__(self):
        """
        Constructor
        """
        self.ball_served = False
        self.previous=(75,400)

    def update(self, scene_info):
        """
        Generate the command according to the received `scene_info`.
        """
        # Make the caller to invoke `reset()` for the next round.
        if (scene_info["status"] == "GAME_OVER" or
            scene_info["status"] == "GAME_PASS"):
            return "RESET"

        if not self.ball_served:
            self.ball_served = True
            command="SERVE_TO_LEFT"
        else:
            x1=scene_info["ball"][0]
            x2=self.previous_ball[0]
            y1=scene_info["ball"][1]
            y2=self.previous_ball[1]
            if y2-y1<0:
                guess_x=(400-y1)*(x1-x2)/(y1-y2)+x1
                if guess_x>200:
                    guess_x=200-(guess_x-200)
                if guess_x<0:
                    guess_x=-guess_x
            else:
                guess_x=100
            if guess_x>(scene_info["platform"][0]+25):
                command="MOVE_RIGHT"
            elif guess_x<(scene_info["platform"][0]+25):
                command="MOVE_LEFT"
            else:
                command="NONE"
        self.previous_ball=scene_info["ball"]
        return command

    def reset(self):
        """
        Reset the status
        """
        self.ball_served = False
