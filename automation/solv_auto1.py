#!/bin/python3

import r2pipe as r2

print("Launching r2pipe on ./auto1")
p = r2.open("./auto1")
p.cmd("s 0x00401143")

print("Parsing data")
line = p.cmdj("pdj 1")[0]
parsed_text = ""
i = 0
while not "ret" in line['disasm']:
    if line['disasm'].startswith("cmp "):
        parsed_text += chr(int(p.cmd("pd 1~cmp[4]"), 16))
        print(f"parsing char {i}", end='\r')
        i += 1
    p.cmd(f"s+ {line['size']}")
    line = p.cmdj("pdj 1")[0]

print()
print("DONE")
print(parsed_text)
