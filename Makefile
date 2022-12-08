# list/Makefile
#
#Makefile fore list implemintation
#
# <Traven Reese>

list: main.c list.c
	gcc main.c list.c -o output -I.
