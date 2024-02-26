# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
# DESC: Some custom module for data encoding on transmission

import socket
import struct
import binascii
from enum import IntFlag, auto


class EncodeType(IntFlag):
	INT = auto() # 0x01, signed int
	STR = auto() # 0x02, byte string

	# future support ?
	CHAR = auto() # 0x03, raw byte
	BOOL = auto() # 0x04
	FLOAT = auto() # 0x05
	DOUBLE = auto() # 0x06
	ARRAY = auto() # 0x00 prefix



class Convert():
	@staticmethod
	def hex_encode(data):
		return binascii.hexlify(data) # for safe transmission, in case raw byte transmission is not supported


	@staticmethod
	def hex_decode(data):
		return binascii.unhexlify(data)


	@staticmethod
	def pack(type, raw_data):
		data = b''

		# check the type it specify before packing
		if (type & EncodeType.ARRAY): # array data type
			count =  len(raw_data) # get number of entry
			data += bytes([0x00]) # make a mark that it's an array

			pass # implement in future

		else: # normal data type
			if (type & EncodeType.INT):
				agent = struct.Struct("!i")
				data += bytes([0x01])
				data += agent.pack(raw_data)

			elif (type & EncodeType.STR):
				length = len(raw_data)
				agent = struct.Struct("!{}s".format(length))
			
				data += bytes([0x02]) # ID 0x02: String
				data += length.to_bytes(4, "big", signed=False) # 4 byte unsigned data length identifier
				data += agent.pack(raw_data.encode('utf-8')) # append the actual payload

			elif (type & EncodeType.CHAR):
				agent = struct.Struct("!c")
				data += bytes([0x03])
				data += agent.pack(raw_data)

			elif (type & EncodeType.BOOL):
				agent = struct.Struct("!?")
				data += bytes([0x04])
				data += agent.pack(raw_data)

			elif (type & EncodeType.FLOAT):
				agent = struct.Struct("!f")
				data += bytes([0x05])
				data += agent.pack(raw_data)

			elif (type & EncodeType.DOUBLE):
				agent = struct.Struct("!d")
				data += bytes([0x06])
				data += agent.pack(raw_data)

		return data


	@staticmethod
	def unpack(packed_data):
		data = ""
		datatype = ""
		id = packed_data[0]

		# # check the format it is packed in
		if (id == 0x00): # array data handling
			id = packed_data[1] # actual type

			# implement in future
			pass

		else: # normal data handling
			if (id == 0x01): # integer format
				print("[TRACE] Detected Int format encoding, now parsing......")
				agent = struct.Struct("!i")
				data = agent.unpack(packed_data[1:])[0]
				datatype = EncodeType.INT

			elif (id == 0x02): # string format
				print("[TRACE] Detected String format encoding, now parsing......")
				length = int.from_bytes(packed_data[1:5], "big", signed=False)
				agent = struct.Struct("!{}s".format(length))
				data = (agent.unpack(packed_data[5:])[0]).decode('utf-8')
				datatype = EncodeType.STR

			elif (id == 0x03): # raw byte
				print("[TRACE] Detected Char format encoding, now parsing......")
				agent = struct.Struct("!c")
				data = agent.unpack(packed_data[1:])[0]
				datatype = EncodeType.CHAR

			elif (id == 0x04): # bool
				print("[TRACE] Detected Bool format encoding, now parsing......")
				agent = struct.Struct("!?")
				data = agent.unpack(packed_data[1:])[0]
				datatype = EncodeType.BOOL

			elif (id == 0x05): # float
				print("[TRACE] Detected Float format encoding, now parsing......")
				agent = struct.Struct("!f")
				data = agent.unpack(packed_data[1:])[0]
				datatype = EncodeType.FLOAT

			elif (id == 0x06): # double
				print("[TRACE] Detected Double format encoding, now parsing......")
				agent = struct.Struct("!d")
				data = agent.unpack(packed_data[1:])[0]
				datatype = EncodeType.DOUBLE

		
		return datatype, data



class Validity():
	
	# check if a string contains a valid number for port
	@staticmethod
	def port(data):
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
	def ip(data):
		try:
			socket.inet_aton(data)
			return True

		except OSError:
			return False



if __name__ == "__main__":
	int_data = Convert.pack(EncodeType.INT, -999)
	str_data = Convert.pack(EncodeType.STR, "Hello World !")
	char_data = Convert.pack(EncodeType.CHAR, b"\x99")
	bool_data = Convert.pack(EncodeType.BOOL, True)
	float_data = Convert.pack(EncodeType.FLOAT, 0.123457)
	double_data = Convert.pack(EncodeType.DOUBLE, 0.123456789012345)

	print()
	print("[DEBUG] Data \'-999\' : ", Convert.hex_encode(int_data))
	print("[DEBUG] Data \'Hello World !\' : ", Convert.hex_encode(str_data))
	print("[DEBUG] Data \'\\x99\' : ", Convert.hex_encode(char_data))
	print("[DEBUG] Data \'True\' : ", Convert.hex_encode(bool_data))
	print("[DEBUG] Data \'0.1234567\' : ", Convert.hex_encode(float_data))
	print("[DEBUG] Data \'0.123456789012345\' : ", Convert.hex_encode(double_data))
	
	print()
	resolved_int = Convert.unpack(int_data)
	resolved_str = Convert.unpack(str_data)
	resolved_char = Convert.unpack(char_data)
	resolved_bool = Convert.unpack(bool_data)
	resolved_float = Convert.unpack(float_data)
	resolved_double = Convert.unpack(double_data)

	print()
	print("[DEBUG] Resolved Int Data : ", resolved_int)
	print("[DEBUG] Resolved Str Data : ", resolved_str)
	print("[DEBUG] Resolved Char Data : ", resolved_char)
	print("[DEBUG] Resolved Bool Data : ", resolved_bool)
	print("[DEBUG] Resolved Float Data : ", resolved_float)
	print("[DEBUG] Resolved Double Data : ", resolved_double)
