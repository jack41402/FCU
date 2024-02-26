# Coded by Eric Chen, 陳禹匡, D1172271
# ISTM, Purdue
#
# Copyright @ All Right Reserved

from ..Base import Networking, Utils


class API:
	def __init__(self, server_address, server_port):
		self.socket = Networking.Client(server_address, server_port)
		self.socket.Receive()
		return


	# Custom API to ease the process of login POP3 server
	def LOGIN(self, username, password):
		# send username for login
		command = "USER " + username +"\r\n"
		self.socket.Send(Utils.Encode_Type.UTF8, command)
		data = self.socket.Receive()

		# send password for login
		command = "PASS " + password +"\r\n"
		self.socket.Send(Utils.Encode_Type.UTF8, command)
		data = self.socket.Receive()

		# check if logged in successfully
		if (data.strip("\r\n") == "+OK Logged in."):
			print("\n[INFO] User login pop3 server successfully.\n")
			return True

		else:
			print("[CRITICAL] User failed to login to pop3 server !")
			return False


	# A dedicated API for receiving the header information of a specific mail
	def TOP(self, index, preview):
		subject = None
		sender = None
		receiver = None
		timestamp = None

		try:
			command = "TOP {id} {count}\r\n".format(id=index, count=preview)
			self.socket.Send(Utils.Encode_Type.UTF8, command)
			data = self.socket.Receive()

			# debug
			print("[TRACE] Successfully executed \'{}\' on the pop3 server".format(command.strip("\r\n")))

			# data purify
			line_data = data.split("\r\n")
			purify_data = line_data[1:-3]

			# search for header tags
			for entry in purify_data:
				if (entry.startswith("To:")): # receiver
					receiver = entry.split(" ")[1]
					print("[INFO] Receiver:", receiver)

				elif (entry.startswith("From:")): # sender
					sender = entry.split(" ")[1]
					print("[INFO] Sender:", sender)

				elif (entry.startswith("Subject:")): # subject
					tmp = entry.split(" ")
					subject = " ".join(tmp[1:])
					print("[INFO] Subject:", subject)

				elif (entry.startswith("Date:")): # timestamp
					tmp = entry.split(" ")
					timestamp = " ".join(tmp[1:-2])
					print("[INFO] Date:", timestamp)

			return (subject, sender, receiver, timestamp)

		except Exception as ex:
			print("[WARNING] Caught Exception:", str(ex))
			return False


	# API for receiving the uid of avalible mail inbox
	def LIST(self):
		mail_uid = []

		try:
			command = "LIST\r\n"
			self.socket.Send(Utils.Encode_Type.UTF8, command)
			data = self.socket.Receive()

			# debug
			print("[TRACE] Successfully executed \'LIST\' on the pop3 server")
			
			# data purify
			line_data = data.split("\r\n")
			purify_data = line_data[1:-2]

			# receiving the mail index
			for entry in purify_data:
				uid = entry.split(' ')[0]
				mail_uid.append(int(uid))

			# return the list containing the mail index
			return mail_uid

		except Exception as ex:
			print("[WARNING] Caught Exception:", str(ex))
			return False


	# A dedicated API for receiving the main content of email
	def RETR(self, index):
		content = None
		
		try:
			command = "RETR {}\r\n".format(index)
			self.socket.Send(Utils.Encode_Type.UTF8, command)
			data = self.socket.Receive()

			# debug
			print("[TRACE] Successfully executed \'{}\' on the pop3 server".format(command.strip("\r\n")))
			
			# data purify
			line_data = data.split("\r\n")
			empty_index = line_data.index("") # find the empty line that split header and body

			# data constructing
			content = "\r\n".join(line_data[empty_index + 1:-2])
			print("[INFO] Extracted Content:\n", content)
			return content

		except Exception as ex:
			print("[WARNING] Caught Exception:", str(ex))
			return False


	# API for deleting a specific email by uid
	def DELE(self, index):
		try:
			command = "DELE " + str(index) + "\r\n"
			self.socket.Send(Utils.Encode_Type.UTF8, command)
			data = self.socket.Receive()

			# debug
			print("[TRACE] Successfully executed \'DELE {}\' on the pop3 server".format(index))
			print("[INFO] Received:\n", data)
			return True

		except Exception as ex:
			print("[WARNING] Caught Exception:", str(ex))
			return False


	# exit the current account, perform the actual deletion
	def QUIT(self):
		try:
			command = "QUIT\r\n"
			self.socket.Send(Utils.Encode_Type.UTF8, command)
			self.socket.Receive()
			return True

		except Exception as ex:
			print("[WARNING] Caught Exception:", str(ex))
			return False