// FIFO page replacement
#include<bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
	// To represent set of current pages. We use an unordered_set so that we quickly check if a page is present in set or not
	unordered_set<int> s;

	// To store the pages in FIFO manner
	queue<int> indexes;

	// Start from initial page
	int page_faults = 0;
	for (int i=0; i<n; i++)
	{
// Check if the set can hold more pages
		if (s.size() < capacity)
		{
			// Insert it into set if not present already which represents page fault
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]); // Insert the current page into the set
				page_faults++;
				indexes.push(pages[i]); 	// Push the current page into the queue
			}
		}

// If the set is full then need to perform FIFO i.e. remove the first page of the queue from set and queue both and insert the current page
		else
		{
			// Check if current page is not already present in the set
			if (s.find(pages[i]) == s.end())
			{
				// Store the first page in the queue to be used to find and erase the page from the set
				int val = indexes.front();
				indexes.pop(); // Pop the first page from the queue
				s.erase(val); // Remove the indexes page from the set

				s.insert(pages[i]); // insert the current page in the set
				indexes.push(pages[i]); // push the current page into the queue
				page_faults++;
			}
		}
	}
	return page_faults;
}

int main()
{
	int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2,0};
	int n = sizeof(pages)/sizeof(pages[0]);
	int capacity = 3;
	int miss= pageFaults(pages, n, capacity);
    cout<<"No. of page faults: "<<miss<<"\nNo. of hits: "<<n-miss<<endl;
 double missRatio= (double)(miss)/n;
 cout<<"Miss Ratio: "<<missRatio;
 cout<<"\nHit ratio: "<<1-missRatio<<endl;

	return 0;
}
