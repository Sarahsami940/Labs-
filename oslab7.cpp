



















































































// ///////////////////   LAB 8
// #include <iostream>
// using namespace std;

// void calculatedifference(int request[], int head,
// 						int diff[][2], int n)
// {
// 	for(int i = 0; i < n; i++)
// 	{
// 		diff[i][0] = abs(head - request[i]);
// 	}
// }

// int findMIN(int diff[][2], int n)
// {
// 	int index = -1;
// 	int minimum = 1e9;

// 	for(int i = 0; i < n; i++)
// 	{
// 		if (!diff[i][1] && minimum > diff[i][0])
// 		{
// 			minimum = diff[i][0];
// 			index = i;
// 		}
// 	}
// 	return index;
// }

// void shortestSeekTimeFirst(int request[], int head, int n)
// {
// 	if (n == 0)
// 	{
// 		return;
// 	}
	
// 	// Create array of objects of class node 
// 	int diff[n][2] = { { 0, 0 } };
	
// 	// Count total number of seek operation 
// 	int seekcount = 0;
	
// 	// Stores sequence in which disk access is done 
// 	int seeksequence[n + 1] = {0};
	
// 	for(int i = 0; i < n; i++)
// 	{
// 		seeksequence[i] = head;
// 		calculatedifference(request, head, diff, n);
// 		int index = findMIN(diff, n);
// 		diff[index][1] = 1;
		
// 		// Increase the total count 
// 		seekcount += diff[index][0]; 
		
// 		// Accessed track is now new head 
// 		head = request[index];
// 	}
// 	seeksequence[n] = head;
	
// 	cout << "Total number of seek operations = "
// 		<< seekcount << endl;
// 	cout << "Seek sequence is : " << "\n";
	
// 	// Print the sequence 
// 	for(int i = 0; i <= n; i++) 
// 	{
// 		cout << seeksequence[i] << "\n";
// 	}
// }

// // Driver code
// int main()
// {
// 	int n = 8;
// 	int proc[n] = { 176, 79, 34, 60, 92, 11, 41, 114 };
	
// 	shortestSeekTimeFirst(proc, 50, n);
	
// 	return 0;
// }











/////////////////////// SCANN ** 9

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void SCAN(vector<int>& request, int head, int direction) {
//     int seekCount = 0;
//     vector<int> sortedRequest = request;

//     // Sort the request array based on track positions
//     sort(sortedRequest.begin(), sortedRequest.end());

//     int currentIndex = 0;

//     if (direction == 0) {
//         // Moving towards higher track numbers
//         while (currentIndex < sortedRequest.size() && sortedRequest[currentIndex] < head) {
//             ++currentIndex;
//         }

//         while (currentIndex < sortedRequest.size()) {
//             int currentTrack = sortedRequest[currentIndex];
//             cout << "Servicing track " << currentTrack << endl;
//             seekCount += abs(currentTrack - head);
//             head = currentTrack;
//             ++currentIndex;
//         }

//         // Move to the highest track
//         cout << "Moving to the highest track" << endl;
//         seekCount += abs(head - 199);
//         head = 199;

//         // Move towards lower track numbers
//         for (int i = currentIndex - 1; i >= 0; --i) {
//             int currentTrack = sortedRequest[i];
//             cout << "Servicing track " << currentTrack << endl;
//             seekCount += abs(currentTrack - head);
//             head = currentTrack;
//         }
//     } else {
//         // Moving towards lower track numbers
//         while (currentIndex < sortedRequest.size() && sortedRequest[currentIndex] < head) {
//             ++currentIndex;
//         }

//         while (currentIndex < sortedRequest.size()) {
//             int currentTrack = sortedRequest[currentIndex];
//             cout << "Servicing track " << currentTrack << endl;
//             seekCount += abs(currentTrack - head);
//             head = currentTrack;
//             ++currentIndex;
//         }

//         // Move to the lowest track
//         cout << "Moving to the lowest track" << endl;
//         seekCount += abs(head - 0);
//         head = 0;

//         // Move towards higher track numbers
//         for (int i = currentIndex - 1; i >= 0; --i) {
//             int currentTrack = sortedRequest[i];
//             cout << "Servicing track " << currentTrack << endl;
//             seekCount += abs(currentTrack - head);
//             head = currentTrack;
//         }
//     }

//     cout << "Total seek count: " << seekCount << endl;
// }

// int main() {
//     // Example with predefined values
//     int head = 50;  // Initial position of the disk head
//     int direction = 0;  // Direction (0 for left, 1 for right)
//     vector<int> request = {176, 79, 34, 60, 92, 11, 41, 114};  // Track requests

//     // Perform SCAN disk scheduling
//     SCAN(request, head, direction);

//     return 0;
// }



//////////  LAB 7 FCFS

// #include <iostream>
// #include <vector>

// using namespace std;

// void FCFS(vector<int>& request, int head) {
//     int seekCount = 0;

//     cout << "Seek sequence is : " << endl;
//     for (int i = 0; i < request.size(); ++i) {
//         int currentTrack = request[i];
//         cout << currentTrack << endl;
//         seekCount += abs(currentTrack - head);
//         head = currentTrack;
//     }

//     cout << "Total seek count: " << seekCount << endl;
// }

// int main() {
//     // Example with predefined values
//     int head = 50;  // Initial position of the disk head
//     vector<int> request = {176, 79, 34, 60, 92, 11, 41, 114};  // Track requests

//     // Perform FCFS disk scheduling
//     FCFS(request, head);

//     return 0;
// }




/////////// LAB 5 

// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <chrono>

// using namespace std;

// const int num_philosophers = 5;
// mutex forks[num_philosophers];

// void philosopher(int id) {
//     while (true) {
//         int left_fork = id;
//         int right_fork = (id + 1) % num_philosophers;

//         if (id % 2 == 0) {
//             forks[left_fork].lock();
//             forks[right_fork].lock();
//         } else {
//             forks[right_fork].lock();
//             forks[left_fork].lock();
//         }

//         cout << "Philosopher " << id << " is eating." << endl;

//         this_thread::sleep_for(chrono::milliseconds(1000));

//         cout << "Philosopher " << id << " is thinking." << endl;

//         forks[left_fork].unlock();
//         forks[right_fork].unlock();

//         this_thread::sleep_for(chrono::milliseconds(1500));
//     }
// }

// int main() {
//     thread philosophers[num_philosophers];

//     for (int i = 0; i < num_philosophers; ++i) {
//         philosophers[i] = thread(philosopher, i);
//     }

//     for (int i = 0; i < num_philosophers; ++i) {
//         philosophers[i].join();
//     }

//     return 0;
// }



// #include <iostream>

// using namespace std;

// int main() {
//     int i, j, temp, blocks[10], c[10], arr, no_of_block, ch, a;

//     cout << "\t\t FIRST FIT, BEST FIT, WORST FIT\n";
//     cout << "Enter the size of no. of blocks: ";
//     cin >> no_of_block;

//     for (i = 1; i <= no_of_block; i++) {
//         cout << "Enter the size of block " << i << ": ";
//         cin >> blocks[i];
//         c[i] = blocks[i];
//     }

//     cout << "\nEnter the file size: ";
//     cin >> arr;

//     cout << "\n1. First fit\n2. Best fit\n3. Worst fit\nEnter your choice by entering the specific number: ";
//     cin >> ch;

//     switch (ch) {
//     case 1:
//         // First Fit
//         for (i = 1; i <= no_of_block; i++) {
//             if (blocks[i] >= arr) {
//                 cout << "Arriving file is allocated to block " << i << ".\n";
//                 break;
//             }
//         }
//         break;

//     case 2:
//         // Best Fit
//         for (i = 1; i <= no_of_block; i++) {
//             for (j = i + 1; j <= no_of_block; j++) {
//                 if (blocks[i] > blocks[j]) {
//                     temp = blocks[i];
//                     blocks[i] = blocks[j];
//                     blocks[j] = temp;
//                 }
//             }
//         }
//         for (i = 1; i <= no_of_block; i++) {
//             if (blocks[i] >= arr) {
//                 a = blocks[i];
//                 break;
//             }
//         }
//         for (i = 1; i <= no_of_block; i++) {
//             if (c[i] == a) {
//                 cout << "Arriving block is allocated to block " << i << ".\n";
//             }
//         }
//         break;

//     case 3:
//         // Worst Fit
//         for (i = 1; i <= no_of_block; i++) {
//             for (j = 1; j < no_of_block; j++) {
//                 if (blocks[j] >= blocks[j + 1]) {
//                     temp = blocks[j];
//                     blocks[j] = blocks[j + 1];
//                     blocks[j + 1] = temp;
//                 }
//             }
//         }
//         for (i = 1; i <= no_of_block; i++) {
//             if (blocks[i] >= arr) {
//                 cout << "Arriving block is allocated to block " << i << ".\n";
//                 break;
//             }
//         }
//         break;

//     default:
//         cout << "Enter a valid choice.\n";
//     }

//     return 0;
// }