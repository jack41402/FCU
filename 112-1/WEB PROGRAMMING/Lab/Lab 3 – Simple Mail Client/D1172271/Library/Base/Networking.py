# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
# DESC: For handling client server connection in a custom way


import socket
from . import Utils 


class Server:

	def __init__(self, bind_interface, bind_port, backlog):
		self.interface = bind_interface
		self.port = bind_port
		self.backlog = backlog
		self.client_connection = None

		self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # specify tcp transmission
		self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # allow port reusing
		self.socket.bind((self.interface, self.port)) # set port & interface


	def Start(self):
		# start listening for incomming client conenction
		self.socket.listen(self.backlog)
		client, addr = self.socket.accept()
		print("[INFO] Receive incomming connection from {ip} via port {port}".format(ip=addr[0], port=addr[1]))
		self.client_connection = client
		return addr


	def Send(self, type, data, hex_encode=False):
		packed_data = None
		encoded_data = None

		# determine the way we will use to encode the data
		try:
			# data packing
			if (type == Utils.Encode_Type.INT): # integer format data
				print("[TRACE] Attempting to pack the current data in Int format......")
				packed_data = Utils.Convert.pack(Utils.Encode_Type.INT, data)

			elif (type == Utils.Encode_Type.STR): # string format data
				print("[TRACE] Attempting to pack the current data in Int format......")
				packed_data = Utils.Convert.pack(Utils.Encode_Type.STR, data)
	
			elif (type == Utils.Encode_Type.UTF8): # utf-8 packing format
				print("[TRACE] Attempting to pack the current data in UTF-8 format......")
				packed_data = Utils.Convert.pack(Utils.Encode_Type.UTF8, data)

			else: # type unknown
				return False

			# data hex encoding
			if (hex_encode):
				encoded_data = Utils.hex_encode(packed_data)

			else:
				encoded_data = packed_data

			self.client_connection.sendall(encoded_data)
			return True


		except OSError as ex:
			print("[ERROR] Send Failed ! Socket Error: \"{}\"".format(ex))
			return False

		except Exception as ex:
			print("[ERROR] Send Failed ! \"{}\"".format(ex))
			return False 


	def Receive(self, autoparse=True, hex_encode=False):
		try:
			raw_data = self.client_connection.recv(2048)

			# empty data received, indicates client closed connection
			if not raw_data:
				return False

			# normal data received, try to decode it
			if (autoparse):
				
				if (hex_encode):
					decoded_data = Utils.Convert.hex_decode(raw_data)

				else:
					decoded_data = raw_data

				unpacked_data = Utils.Convert.unpack(decoded_data)
				return unpacked_data

			else:
				return raw_data


		except OSError as ex:
			print("[ERROR] Receive Failed ! Socket Error: \"{}\"".format(ex))
			return False

		except Exception as ex:
			print(raw_data)
			print("[ERROR] Receive Failed ! \"{}\"".format(ex))
			return False


	def Close(self):
		try:
			print("[TRACE] Closing server socket......")
			self.client_connection.close() # cleanup client handle
			self.socket.close() # cleanup server port binding
			return

		except OSError as ex:
			return


class Client:

	def __init__(self, server_address, server_port):
		self.server_ip = server_address
		self.server_port = server_port

		self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # tcp 
		self.socket.connect((self.server_ip, self.server_port))
		return


	def Send(self, type, data, hex_encode=False):
		packed_data = None
		encoded_data = None

		# determine the way we will use to encode the data
		try:
			# data packing
			if (type == Utils.Encode_Type.INT): # integer format data
				print("[TRACE] Attempting to pack the current data in Int format......")
				packed_data = Utils.Convert.pack(Utils.Encode_Type.INT, data)

			elif (type == Utils.Encode_Type.STR): # string format data
				print("[TRACE] Attempting to pack the current data in Int format......")
				packed_data = Utils.Convert.pack(Utils.Encode_Type.STR, data)
	
			elif (type == Utils.Encode_Type.UTF8): # utf-8 packing format
				print("[TRACE] Attempting to pack the current data in UTF-8 format......")
				packed_data = Utils.Convert.pack(Utils.Encode_Type.UTF8, data)

			else: # type unknown
				return False

			# data hex encoding
			if (hex_encode):
				encoded_data = Utils.hex_encode(packed_data)

			else:
				encoded_data = packed_data

			self.socket.sendall(encoded_data)
			return True


		except OSError as ex:
			print("[ERROR] Send Failed ! Socket Error: \"{}\"".format(ex))
			return False

		except Exception as ex:
			print("[ERROR] Send Failed ! \"{}\"".format(ex))
			return False


	def Receive(self, autoparse=True, hex_encode=False):
		try:
			raw_data = self.socket.recv(2048)
			# empty data received, indicates client closed connection
			if not raw_data:
				return False

			# normal data received, try to decode it
			if (autoparse):
				
				if (hex_encode):
					decoded_data = Utils.Convert.hex_decode(raw_data)

				else:
					decoded_data = raw_data

				unpacked_data = Utils.Convert.unpack(decoded_data)
				return unpacked_data

			else:
				return raw_data


		except OSError as ex:
			print("[ERROR] Receive Failed ! Socket Error: \"{}\"".format(ex))
			return False

		except Exception as ex:
			print(raw_data)
			print("[ERROR] Receive Failed ! \"{}\"".format(ex))
			return False


	def Close(self):
		print("[TRACE] Closing clinet socket......")
		self.socket.close() # cleanup
		return


# for local debug
def local_main():
	return


if __name__ == "__main__":
	local_main()