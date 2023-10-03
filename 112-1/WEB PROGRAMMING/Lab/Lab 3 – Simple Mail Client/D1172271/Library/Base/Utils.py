# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
# DESC: Some custom module for data encoding on transmission


import socket
import struct
import binascii
from enum import Enum, auto


class Encode_Type(Enum):
	UTF8 = auto()
	INT = auto()
	STR = auto()


class Convert():
	@staticmethod
	def hex_encode(data):
		return binascii.hexlify(data)


	@staticmethod
	def hex_decode(data):
		return binascii.unhexlify(data)


	@staticmethod
	def pack(type, raw_data):
		data = b''

		# check the type it specify before packing
		if (type == Encode_Type.INT):
			print("[TRACE] Selected INT packing style")
			agent = struct.Struct("!I")
			data += bytes([0x01])
			data += agent.pack(raw_data)
			return data

		elif (type == Encode_Type.STR):
			print("[TRACE] Selected STRING packing style")
			length = len(raw_data)
			agent = struct.Struct("!{}s".format(length))
			
			data += bytes([0x02]) # ID 0x02: String
			data += length.to_bytes(4, "big", signed=False) # 4 byte unsigned data length identifier
			data += agent.pack(raw_data.encode('utf-8')) # append the actual payload
			return data

		elif (type == Encode_Type.UTF8):
			print("[TRACE] Selected UTF-8 packing style")
			data += raw_data.encode("utf-8")
			return data

		else:
			return data


	@staticmethod
	def unpack(packed_data):
		data = ""
		id = packed_data[0]

		# check the format it is packed with
		if (id == 0x01): # integer format
			print("[TRACE] Detected Int format encoding")
			agent = struct.Struct("!I")
			data = agent.unpack(packed_data[1:])[0]
			return (Encode_Type.INT, data)

		elif (id == 0x02): # string format
			print("[TRACE] Detected String format encoding")
			length = int.from_bytes(packed_data[1:5], "big", signed=False)
			agent = struct.Struct("!{}s".format(length))
			data = (agent.unpack(packed_data[5:])[0]).decode('utf-8')
			return (Encode_Type.STR, data)

		else:
			return packed_data.decode("utf-8")


class Validity():
	
	# check if a string contains a valid number for port
	@staticmethod
	def Port(data):
		# If all letters contained are digits
		if (data.isdigit()):
			# then check if it is in range of 1 ~ 65535
			if (1 <= int(data) <= 65535):
				return True

			else:
				print("Data not in range")
				return False

		else:
			print("Not digit")
			return False

	# check if a string contains a valud ip address
	@staticmethod
	def IP(data):
		try:
			socket.inet_aton(data)
			return True

		except OSError:
			return False


if __name__ == "__main__":
	int_data = Convert.pack(Encode_Type.INT, 999)
	str_data = Convert.pack(Encode_Type.STR, "Hello World !")

	print()
	print("[DEBUG] Data \'999\' : ", Convert.hex_encode(int_data))
	print("[DEBUG] Data \'Hello World !\' : ", Convert.hex_encode(str_data))
	
	print()
	resolved_int = Convert.unpack(int_data)
	resolved_str = Convert.unpack(str_data)

	print()
	print("[DEBUG] Resolved Int Data : ", resolved_int)
	print("[DEBUG] Resolved Str Data : ", resolved_str)