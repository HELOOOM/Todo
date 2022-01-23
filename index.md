# ToDo Application using containers

BY : Lakhmiri / Sakassa / Benzemroun

## Introduction
### **TODO** List are the lists that we generally use to maintain our day to day tasks or list of everything that we have to do. It is helpful in planning our daily schedules. We can add more tasks any time and delete a task which is completed. The four major tasks that we can perform in a TODO list are:

1. Add tasks
2. Update tasks
3. Read tasks
4. Delete tasks


## First let's describe our application
### In our Task Manager application we have:
1. A menu bar containing : "File , Options , Help"
   - file menu containing : "New , Exit"
     - **_New_** is an action which can add a new task to our application
     - **_Exit_** is an action which **save** the contents befor leaving the application
   - options menu containing : "Delete, show all, show pending task, show finished task, show today task"
     - **_Delete task_** is an action which can delete a selected task
     - **_Show all_** is an action which show pending,today and finished task
     - **_Show pending_** is an action which show pending task
     - **_Show finished_** is an action which show finished task
     - **_Show today task_** is an action which show today task
   - Help menu containing : "About , About Qt"
2. A Tool bar containing actions like : "new task, show finished, show pending, delete, exit"
3. A List view; in our application we have tree each one display a specific type of tasks
   
# our application look like this:
![image](https://user-images.githubusercontent.com/53974876/150644640-0ee5e304-e3f2-4e39-b20e-95321bdb8a71.png)

- ### when you click **N** (in your keyboard) or presing new file in the application a Qdialoge will pop out

![image](https://user-images.githubusercontent.com/53974876/150644932-c500a620-9f5e-4d16-a10f-ff85d63bf88b.png)

## this QDialog is containing 
1. A description for your task 
2. A check box for finished tasks
3. tags 
4. date for the task (for today or for a specifique date)
5. two push buttons (ok and cancel)



- ## let's make (today, tomorrow and a finished task) with our application, after creating each one now we can see the tasks in the appropriate list 

![image](https://user-images.githubusercontent.com/53974876/150645421-5cb99089-212a-4f38-81ed-b4f9949a0b00.png)

- ### now we want to place a pending task in the listView of today task 
1. first we double click on the task 
2. the Qdialog will pop out to change the description and the date for the selected task
3. after changing the date you press ok 

![image](https://user-images.githubusercontent.com/53974876/150645875-940b7ad8-7774-41d2-be49-a155ac9efb1b.png)

- ### now you can see the task go from pending tasks to today tasks

![image](https://user-images.githubusercontent.com/53974876/150645881-25d6726a-209f-49fa-9142-cc53a9106538.png)

- ### to delete a task you click on it then you press the delet icon in the tool bar

![Untitled-1](https://user-images.githubusercontent.com/53974876/150646443-66a0756c-b9ff-45ba-97c5-8afddf202ac8.png)

- ### To save and exit the application press exit icon in the tool bar then press ok

![Screenshot-2022-01-22-171020](https://user-images.githubusercontent.com/53974876/150646724-6e89aeff-266c-4264-81d8-5429ef43833a.png)

- ### if you want to check your saves go to the `build-tasksmanager-Desktop_Qt_5_15_0_MinGW_64_bit-Debug` folder

![image](https://user-images.githubusercontent.com/53974876/150646852-22d77763-2d50-4895-b388-b5875f522ee5.png)

    
### **To result with such a functional application you have to go through multiple functions, slots, actions and methods (But don't worry we will explain the functionality and role of each part of our code)** 


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```diff 
@@ gfngn @@
```
- [x] #739


- [ ] ldkhfds\kl 
