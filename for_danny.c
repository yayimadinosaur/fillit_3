look at file test_ptr.c

creat_store > creates the storage for each shape
				mallocs *t_store (pointer struct t_store) * shape_count + 1
						this accounts 
				each shape will have 4 #'s; so we create 5 int's inside the *stored (ptr inside t_store struct)
				
				at the end of the create_store function, it runs ft_store_auto
								this function automatically stores the values of each # (0 - 3) from its positioning on the str[i];

				FUNCTION -> creates *ptr array to store values, sets those values with ft_store auto; prints stored values per shape

				//Look at MAIN

test_linkedlist_grid > shows how to make grid; fill grid; and print grid
					//LOOK AT MAIN
					//
					//change the n value to change the grid size ; remove while loop in main

t_list		**ft_placement(t_list **grid, t_store **stored_values, int shape_count);
							^grid[i][j].content;	^
													^stored_values->stored[j];
