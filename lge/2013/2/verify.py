#! /usr/bin/env python

import sys

box_coords = []
box_sizes = []

rl = sys.stdin.readline

def overlap_check():
    global box_coords
    for b1 in range( num_boxes ):
        for b2 in range( num_boxes ):
            if b1 == b2:
                continue
            x1, y1, rotation1 = box_coords[ b1 ]
            width1, height1 = box_sizes[ b1 ]
            x2, y2, rotation2 = box_coords[ b2 ]
            width2, height2 = box_sizes[ b2 ]
            if rotation1 == 1:
                width1, height1 = height1, width1
            if rotation2 == 1:
                width2, height2 = height2, width2
            # overlap check
            if x1 <= x2 + width2 - 1 and x1 + width1 - 1 >= x2 and y1 <= y2 + height2 - 1 and y1 + height1 - 1 >= y2:
                return (b1, b2)
    return None

if len( sys.argv ) < 3:
    print "Insufficent arguments"
    print "Usage: ", sys.argv[0], "<input file> <output file>"
    exit()

# read an input file
input_file = sys.argv[1]
output_file = sys.argv[2]

input_file = open( input_file, 'r' )
input_lines = input_file.readlines()
input_file.close()

num_boxes = int( input_lines[0].strip() )

for line in input_lines[1:]:
    width, height = map( int, line.strip().split() )
    box_sizes.append( ( width, height ) )

# read a matching output file
output_file = open( output_file, 'r' )
output_lines = output_file.readlines()
output_file.close()

out_width, out_height = map( int, output_lines[0].strip().split() )
print "Your answer"
print "Width:", out_width
print "Height:", out_height
print "Size:", out_width * out_height

# The width must be greather than or equal to the height
if out_width < out_height:
    print "Invalid ratio"
    print "The width must be greater than or equal to the height"
    exit()

areas = map( lambda( coords ): coords[0] * coords[1], box_sizes )
if out_width * out_height < sum( areas ):
    print "Invalid size"
    print "The box is smaller than sum of all sizes of boxes"
    exit()

index = 0
max_x = 0
max_y = 0

for line in output_lines[1:]:
    x, y, rotation = map( int, line.strip().split() )
    box_coords.append( ( x, y, rotation ) )
    width, height = box_sizes[ index ]
    if rotation == 1:
        width, height = height, width
    if max_x < x + width:
        max_x = x + width
    if max_y < y + height:
        max_y = y + height
    index = index + 1

print
print "Actual size:"
print "Width:", max_x
print "Height:", max_y
print "Size:", max_x * max_y
print

if out_width * out_height != max_x * max_y:
    print "Invalid Answer"
    print "The size doesn't match"
    exit()

print "Check overlap..."
res = overlap_check()
print "done."
print

if res != None:
    print "Invalid answer"
    print "Your answer contains an overlapped box:", res[0], "and", res[1]
    exit()

if ( out_width, out_height, out_width * out_height ) == ( max_x, max_y, max_x * max_y ):
    print "Valid answer"
    print "Efficiency:", sum( areas ) * 1.0 / ( max_x * max_y ) * 100, "%"
    print "Wasted:", 100 - sum( areas ) * 1.0 / ( max_x * max_y ) * 100, "%"
else:
    print "Invalid answer"
    print "The size doesn't match"
