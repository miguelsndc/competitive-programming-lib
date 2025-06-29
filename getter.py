import random

input_file = "upsolve.txt"
output_file = "week.txt"

with open(input_file, "r") as f:
    lines = f.read().splitlines()
    unique_lines = list(dict.fromkeys(line for line in lines if line.strip()))

random.shuffle(unique_lines)

template_items = unique_lines[:4]
remaining_items = unique_lines[4:]

with open(output_file, "w") as f:
    f.write("UPSOLVE THIS WEEK\n\n")
    f.write("\n".join(template_items))
    f.write("\n\n")

with open(input_file, "w") as f:
    f.write("\n".join(remaining_items))
