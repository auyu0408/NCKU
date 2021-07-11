"""
The template of the script for the machine learning process in game pingpong
"""

def adjust(loc):
    while loc>200 or loc<0:
        if loc>200:
            loc=200-(loc-200)
        else:
            loc=-loc
    return loc

def adjust_b(block):
    while block>170 or block<0:
        if block>170:
            block=170-(block-170)
        else:
            block=-block
    return block

class MLPlay:
    def __init__(self, side):
        """
        Constructor

        @param side A string "1P" or "2P" indicates that the `MLPlay` is used by
               which side.
        """
        self.ball_served = False
        self.side = side
        self.previous=(0,240)

    def update(self, scene_info):
        """
        Generate the command according to the received scene information
        """
        if scene_info["status"] != "GAME_ALIVE":
            print(scene_info["ball_speed"])
            return "RESET"

        if not self.ball_served:
            self.ball_served = True
            return "SERVE_TO_LEFT"
        else:
            if scene_info["ball_speed"][1]<0:
                t=(240-scene_info["ball"][1])/scene_info["ball_speed"][1]
            else:
                t=(scene_info["ball"][1]-260)/scene_info["ball_speed"][1]
            loc_mid=scene_info["ball"][0]+scene_info["ball_speed"][0]*t
            block=scene_info["blocker"][0]+(scene_info["blocker"][0]-self.previous[0])*t
            loc_mid=adjust(loc_mid)
            block=adjust_b(block)
            if loc_mid+30>=block or loc_mid<=block:
                if scene_info["ball_speed"][1]<0:
                    t=(85-scene_info["ball"][1])/scene_info["ball_speed"][1]
                    if loc_mid+30==block or loc_mid==block:
                        loc_x=scene_info["ball"][0]-scene_info["ball_speed"][0]*t
                    else:
                        loc_x=scene_info["ball"][0]+scene_info["ball_speed"][0]*t
                    loc_x=adjust(loc_x)
                    if scene_info["platform_2P"][0]+10>loc_x:
                        command="MOVE_LEFT"
                    elif scene_info["platform_2P"][0]+30<loc_x:
                        command="MOVE_RIGHT"
                    else:
                        command="NONE"
                else:
                    t=(415-scene_info["ball"][1])/scene_info["ball_speed"][1]
                    if loc_mid+30==block or loc_mid==block:
                        loc_x=scene_info["ball"][0]-scene_info["ball_speed"][0]*t
                    else:
                        loc_x=scene_info["ball"][0]+scene_info["ball_speed"][0]*t
                    loc_x=adjust(loc_x)
                    if scene_info["platform_1P"][0]+10>loc_x:
                        command="MOVE_LEFT"
                    elif scene_info["platform_1P"][0]+30<loc_x:
                        command="MOVE_RIGHT"
                    else:
                        command="NONE"
            else:
                if scene_info["ball_speed"][1]<0:
                    speed_y=-scene_info["ball"][1]
                    t=(415-260)/speed_y
                    loc_x=scene_info["ball"][0]+scene_info["ball_speed"][0]*t
                    loc_x=adjust(loc_x)
                    if scene_info["platform_1P"][0]+10>loc_x:
                        command="MOVE_RIGHT"
                    elif scene_info["platform_1P"][0]+30<loc_x:
                        command="MOVE_LEFT"
                    else:
                        command="NONE"
                else:
                    speed_y=-scene_info["ball"][1]
                    t=(85-240)/speed_y
                    loc_x=scene_info["ball"][0]+scene_info["ball_speed"][0]*t
                    loc_x=adjust(loc_x) 
                    if scene_info["platform_2P"][0]+10>loc_x:
                        command="MOVE_RIGHT"
                    elif scene_info["platform_2P"][0]+30<loc_x:
                        command="MOVE_LEFT"
                    else:
                        command="NONE"
        self.previous=scene_info["blocker"]
        return command
    def reset(self):
        """
        Reset the status
        """
        self.ball_served = False
