#include "OrganizeContainer.h"

string organizingContainers(vector<vector<int>> container)
{
	string res = "Impossible";

	const int Containers = static_cast<int>(container.size());
	const int Colors     = static_cast<int>(container.size());

	vector<int> contSize(Containers, 0);
	vector<int> typSize(Colors, 0);

	for (int i = 0; i < Containers; i++)
	{
		contSize[i] = accumulate(container[i].begin(), container[i].end(), 0);
		for (int j = 0; j < Colors; j++)
		{
#ifdef DEBUG
			cout << container[i][j] << " ";
#endif // DEBUG			
			typSize[j] += container[i][j];
		}
#ifdef DEBUG
		cout << " = " << contSize[i] << endl;
#endif // DEBUG		
	}
#ifdef DEBUG
	for (int i = 0; i < Colors; i++)
	{
		cout << typSize[i] << " ";
	}
	cout << endl;
#endif // DEBUG

	sort(contSize.begin(), contSize.end());
	sort(typSize.begin(), typSize.end());

	bool isEqual = equal(contSize.begin(), contSize.end(), typSize.begin(), typSize.end());

	if (isEqual)
	{
		res = "Possible";
	}

	return res;
}