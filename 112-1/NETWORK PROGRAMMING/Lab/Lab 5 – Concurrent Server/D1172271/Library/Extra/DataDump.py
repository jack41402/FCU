# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
# DESC: hexdump() module for phrasing byte string


class ByteString:
    @staticmethod
    def hexdump(data, step):
        result = []
        for x in range(0, len(data), step):
            buffer = []  # a list to store hex code

            for y in data[x: x + step]:
                code = '%02x' % y
                buffer.append(code)  # store the first line of hex code to list
            hexcode = ''.join(buffer)
            buffer.clear()

            for z in range(0, len(hexcode), 4):  # 2 hexcode in a group
                groupcode = hexcode[z: z + 4]
                buffer.append(groupcode)
            hexcode = ' '.join(buffer)  # join each group and split with space

            normal_len = step*2.5 - 1
            if len(hexcode) != normal_len:
                patch = normal_len - len(hexcode)
                for i in range(0, int(patch), 1):
                    hexcode = hexcode + ' '  # fill the space in hexcode with space
            else:
                pass

            #output = hexcode + ' | ' + text  # make a nice format
            result.append(hexcode)  # store each line to list

        output = '\n'.join(result)
        return output


    @staticmethod
    def asciidump(data, step):
        result = []
        for x in range(0, len(data), step):
            text = ""

            for char in data[x: x + step]:
                if (char >= 0x7F): # unvisible
                    text += '.'

                elif (char < 0x20): # unvisible
                    text += '.'

                else:
                    text += chr(char)

            result.append(text)

        output = '\n'.join(result)
        return output


# testing
if __name__ == '__main__':
    print("[#]Modele executed locally")
    print()
    print(ByteString.hexdump(b'01000001bc', 4))
    print(ByteString.asciidump(b'01000001bc', 8))