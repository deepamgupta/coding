// https://stackoverflow.com/questions/1412751/find-largest-and-second-largest-element-in-a-range
**C++** code to find indexes of *largest* and second-largest numbers in a vector. You can do the same for array as well.

```
// input vector
vector<int> nums = {6, 5 2 9 3 5};

// declare variables to first index
int largest_index = 0, sec_largest_index = 0;

if (nums[0] >= nums[1])
{
    largest_index = 0, sec_largest_index = 1;
}
else
{
    largest_index = 1, sec_largest_index = 0;
}
if (nums.size() >= 3)
{
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] > nums[sec_largest_index])
        {
            if (nums[i] > nums[largest_index])
            {
                sec_largest_index = largest_index;
                largest_index = i;
            }
            else
            {
                sec_largest_index = i;
            }
        }
    }
}
```