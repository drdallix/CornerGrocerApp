# CornerGrocerApp

This project was made to help a client keep better track of their inventory. This software reads a backup file and provides an interactive search function and a histogram and table of what produce items are available and how many are. In addition, it interfaces with a text file and stores frequency information in a plain text backup upon startup. This application has now been enhanced with 8-bit color for the user's experience.
I did an excellent job with the segmentation of classes. Very little memory is shared between the classes, and they handle output and error handling within the class, so the main class is free from clutter. I am also proud of this project's error handling and color enhancements.
I could have improved my code by having a "Print" class, thereby separating some of the logic from the output to make the logic more portable. For example, this may have let me only write one for loop to output the item name and frequency and call a different print method depending on whether they want a histogram or list. This would have reduced repeated code and simplified some other functions.
I found the logic to looping over a map counterintuitive until I found a tutorial on GeeksForGeeks (Traversing a map (or UNORDERED_MAP) in C++ STL 2022) that explained the topic remarkably well for me. I followed their tutorial until I had a demo working on the ItemMap. Once I understood how the first and second fields worked and related that python knowledge, I was confident! I will use GeeksForGeeks again for tutorials since I enjoy how they jump into the code. 
Knowledge of pointers and references was a significant milestone in my development as a developer. While I may not necessarily be required to write C code, I must revisit the language as many tools I use have their roots in C++. Mastering the concepts of manual memory management and thinking in terms of references and pointers will enable me to transfer essential skills that can be applied across a range of contexts.
I went overkill on the comments so that when I came back, I would remember what I wrote all at once. To help with expandability, I used constants to define the highest menu option so that I wouldn't have to change a magic number everywhere if I wanted to add more items to my menu. I also used a consistent approach to my method and variable naming so that other developers would understand what they were by name!



References:

GeeksForGeeks. (2022, July 7). Traversing a map (or UNORDERED_MAP) in C++ STL. GeeksforGeeks. Retrieved February 21, 2023, from https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/
	
