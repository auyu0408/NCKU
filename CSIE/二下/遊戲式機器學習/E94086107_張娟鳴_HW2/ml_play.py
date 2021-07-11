import random
import os.path
import pickle

class MLPlay:
	def __init__(self,side):
		filename = 'model.pickle'
		filepath = os.path.join(os.path.dirname(__file__), filename)
		self.model = pickle.load(open(filepath, "rb"))
		self.ball_served = False
		self.side = side
		
	def update(self, scene_info):
		if scene_info["status"] != "GAME_ALIVE":
			print(scene_info["ball_speed"])
			return "RESET"

		if not self.ball_served:
			self.ball_served = True
			command = "SERVE_TO_LEFT"
		else:
			x = scene_info["ball"][0]
			y = scene_info["ball"][1]
			vx = scene_info["ball_speed"][0]
			vy = scene_info["ball_speed"][1]
			px = scene_info["platform_2P"][0]
			bx = scene_info["blocker"][0]
			ans = self.model.predict([[x,y,vx,vy,px]])
			if ans  == 1:
				command = "MOVE_LEFT"
			elif ans == 2: 
				command = "MOVE_RIGHT"
			else:
				command = "NONE"
		return command

	def reset(self):
		self.ball_served = False
