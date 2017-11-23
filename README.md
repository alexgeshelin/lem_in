# lem_in

One of School 42 learning projects. Goal is to find the most efficent way to guide n ants throughthe "ant farm", which is represented by graph.

Program receives from standart output represantation of a farm in a following format:

    number_of_ants
    the_rooms
    the_links


The ant farm is defined by the following links:
  
    ##start
    1 23 3
    2 16 7
    #comment
    3 16 3
    4 16 5
    5 9 3
    6 1 5
    7 4 8 
    ##end
    0 9 5
    0-4
    0-6
    1-3
    4-3
    5-2
    3-5
    #another comment
    4-2
    2-1
    7-6
    7-2
    7-4
    6-5
    
Which corresponds to the following representation:

                     ______________
                  /                 \
          ______[5]----[3]----[1]   |
        /               |     /     |
       [6]-----[0]-----[4]   /      |
        \    _________/ |   /       |
         \ /           [2]/________/
         [7]_________ /

Then program outputs representation of farm and how ants go through it. Each line is one turn. Ln is number of an ant and then
there is a name of room in which it is at the moment:
    
    $ ./lem-in < subjet2.map
    3
    2 5 0
    ##start
    0 1 2
    ##end
    1 9 2
    3 5 4
    0-2
    0-3
    2-1
    3-1
    2-3

    L1-3 L2-2
    L1-1 L2-1 L3-3
    L3-1
    $

(More details can be found in subject lem_in.en.pdf)
