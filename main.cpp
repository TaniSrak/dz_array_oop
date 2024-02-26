#include <iostream>
#include <memory>

template<typename T>
class DynamicArray
{
public:
	void Add(T element)
	{
		if (currentSize_ != 0)
		{
			if (currentSize_ < maxEmptySize_)
			{
				elementPointer_++;
			}
			else
			{
				ResizeCollection();
				Add(element);
			}
		}
		data_[elementPointer_] = element;
		currentSize_++;
	}

	int GetSixe()
	{
		return currentSize_;
	}

	int IndexOf(T element)
	{
		for (size_t i = 0; i < currentSize_; i++)
		{
			if (data_[i] == element)
			{
				return i;
			}
		}
		return -1;
	}
	
	void Remove(T element)
	{
		int elementIndex = IndexOf(element);
		if (IndexOf(element) != -1)
		{
			for (size_t i = elementIndex; i < currentSize_ -1; i++)
			{
				data_[i] = data_[i + 1];
			}
			currentSize_--;
		}
	}

	DynamicArray()
	{
		currentSize_ = 0;
		elementPointer_ = 0;
		data_ = new T[maxEmptySize_];
	}

	~DynamicArray()
	{
		delete[] data_;
	}

	T operator[](unsigned index) const
	{
		if (index >= currentSize_)
		{
			return NULL;
		}
		return data_[index];
	}

private:
	T* data_;
	unsigned currentSize_;
	unsigned maxEmptySize_ = 100;
	unsigned elementPointer_;

	void ResizeCollection()
	{
		maxEmptySize_ *= 2;
		T* nCollection = new T[maxEmptySize_];

		for (int i = 0; i < currentSize_; i++)
		{
			nCollection[i] = data_[i];
		}
		
		data_ = nCollection;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	DynamicArray<int> list = DynamicArray<int>();
	list.Add(5);
	list.Add(2);
	list.Add(1);

	list.Remove(5);

	DynamicArray<std::string> list1 = DynamicArray<std::string>();
	list1.Add("arkhgk");
	list1.Add("mama");
	list1.Add("dad");

	list1.Remove("mama");

	for (size_t i = 0; i < list.GetSixe(); i++)
	{
		std::cout << list[i] << std::endl;
	}

	for (size_t i = 0; i < list1.GetSixe(); i++)
	{
		std::cout << list1[i] << std::endl;
	}

	return 0;
}