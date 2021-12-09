Administrative 
Team name: Connection Explorers
Team members: Muning Chen, Shoujing Ke, Xizhe Li
Github URL: https://github.com/muning0109/COP3530FinalProject
Link to video: https://youtu.be/Z1xz3UtESIM
 
Extended and refine proposal:
Problem: What problem are we trying to solve?
We are trying to design a graph structure to show the relationship between the email sender and receiver. 
If one sender sends an email to a receiver, we mark them know each other. 
If one sender sends an email to multiple people, and one of the recipients sends an email to the person that the sender knows, so that we can deduce that they know each other. 

Motivation: Why is this a problem? 
Nowadays, meeting new friends is a big problem due to the explosive growth of technology or the epidemic. People usually put 80% to 90% of their social networking on the Internet. So we want to design a recommendation system that can recommend a new friend to a person, and people usually think that friend’s friend are more trustworthy than strangers. It is easier to know a friend’s friend than to know a stranger, and it is also easier to promote the relationship between them.

Features implemented
Graph structure
BFS
DFS
GUI

Description of data
Data set was searched from the internet.
Each line contains a vertice with “From” and “To” integers.
There are 367,662 sets of data.

Tools/Languages/APIs/Libraries used
Clion - where we write the code
C++ (Clang Compiler)
STL, SFML

Graph Algorithms implemented
Graph structure
BFS
DFS

Additional Data Structures/Algorithms used
Use SFML to implement GUI.
Map, vector

Distribution of Responsibility and Roles: Who did what?
Muning Chen: Implemented graph structure, DFS, bug fix, 
  managed Github repository
  recorded presentation.
Xizhe Li: implemented BFS and path generating algorithm
               Fixed the bug with displaying path on interface.
Shoujing Ke: designed the program interface
                     Using the SFML to implement the interface
                     Fixed bugs
Analysis 
Change: 
In order to show the difference between the two algorithms clearly, we decided to display every passing node instead of just showing the distance.
We also noticed that in a social network, it is common for everyone to be connected by each other. Therefore, it is rare to have a situation where there is no connection between two nodes. As a result, we gave up the idea of finding social groups by detecting possible circles in the graph because there are too many of them.
Another change we made about our project is that we choose to not make it as a desktop application. We got the dataset from online as a text file and created a graph directly from it. We think there is no need to make it an application because it may not be useful in our real life. But if we wanna scrap data and use it in the future, we will consider creating an app and adding more useful features. 
Complexity analysis
Our graph is implemented as an adjacent list.
The worst time complexity of Depth first search is O(|V| + |E|). |V| is the number of vertices and |E| is the number of edges.
The worst time complexity of Breadth first search is O(|V| + |E|). |V| is the number of vertices and |E| is the number of edges.

Reflection 
Xizhe Li: 
Overall, It was lucky for me to work well with my group members. As a group, we were able to make the decision quickly and work on the project individually. And luckily, there is no team member procrastinating on their part. The most challenging part is brainstorming because the graph is a new concept to us and it is difficult to come up with an application using a graph. But I believe that we now have a better understanding of graphs after this project. If I were to start once again as a group, I would try to be more ambitious. To be more specific, we can try to analyze some real cases in the industries. I learned how to use GitHub to cooperate with my team members and this experience is priceless for me.

Muning Chen:
	I think overall my group did an excellent job of collaborating and working on the project. Everyone cares about the project and contributes their work. One challenge we faced is with GitHub collaboration. The text file we read in is located in our cmake-debug folder, which is a relative path so that it can work on different people’s computers. However, when we update to the main branch for other teammates to sync project progress, we had problems with different file paths.
	To solve this problem, Shoujing wrote a gitignore file that enabled us to only update certain changes when making local changes. However, this approach did not work. Finally, what we figured out is that we can solve the file path problem by simply clicking Tool -> CMake -> Reload Cache and reload Project.
	After working on this project, I realized the significance of effective communication and became more familiar with the process of collaborating on github. I am satisfied with our progress and don’t think we would change anything if starting over again. I think Shoujing did a good job on implementing the interface. I also appreciate how Xizhe coded the displaying path function.	

Shoujing Ke:
	First of all, thanks to every member of the team for their efforts. Everyone has completed all the requirements very well. I had a very tacit week with my team. We assigned tasks respectively and then completed the tasks Efficiently. When we encounter problems, we start a meeting to discuss solutions. This is a very perfect team. At the same time, I believe this project is very valuable. Such an open theme can enable us to do meaningful things, such as solving some real-world problems. It not only teaches us how to become excellent team members but also highlights each of us' strengths and understanding of the project.
In the process of dealing with this project, I encountered some problems, but later I solved them perfectly. Problem 1: I found many problems in the process of writing SFML. The most important one is the environment configuration because I have been using g++ and gcc to compile c++, which led to a series of errors on the MacOs. After a lot of time query, I locked the problem, so I switched g++ to clang and solved the problem. The second problem is the use of GitHub. I spent several hours learning the terminal command of GitHub. Starting from the principle of GitHub, I understand how GitHub work and the principle of GitHub.
If I restart this project, I may modify the code to make it more efficient and compact. I may not modify other codes, because I think the general direction of the project is right. Compared with modification, I think I will add other methods to make this project more comprehensive.
In this project, each of us plays a vital role and completes the task excellently. First of all, Muning Chen, whose major is data science, used her expertise to find the data set required for this project. At the same time, she wrote a very excellent DFS method and graph structure. She has made a very high contribution to the team. Next is Xizhe Li. His BFS method is simple and efficient. due to his understanding of the graph algorithm, he completed the algorithm very quickly and helped me solve the problem of displaying time in SFML. He also has a high contribution to the team. Finally, I wrote the GUI framework. I have accomplished the tasks assigned by the team as a member of the team. Finally, for the whole team, I appreciate every member of my team for completing the whole project in advance, quickly, and excellently.

