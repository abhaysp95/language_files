#include <iostream>

class dumb_array
{
	public:
		// constructor
		dumb_array(std::size_t size = 0)
			: mSize(size),
			mArray(mSize ? new int[mSize]() : nullptr)
			{}
		// copy-constructor
		dumb_array(const dumb_array& other)
			: mSize(other.mSize),
			mArray(mSize ? new int[mSize] : nullptr)
			{
				std::copy(other.mArray, other.mArray + mSize, mArray);
			}
		// destructor
		~dumb_array()
		{
			delete[] mArray;
		}

		// A failed solution
		/*dumb_array& operator=(const dumb_array& other)
		{
			if(this != &other)
			{
				// get new data ready, before replacing old
				std::size_t newSize = other.mSize;
				int* newArray = newSize ? new int[newSize]() : nullptr;
				std::copy(other.mArray, other.mArray + newSize, newArray);

				// replace the old data(all are non-throwing)
				delete[] mArray;
				mSize = newSize;
				mArray = newArray;

			}
			return *this;
		}*/
		/** ---------------- */

		// custom swap function(swap is non-throwing)
		friend void swap(dumb_array& first, dumb_array& second) noexcept
		{
			// enable ADL
			using std::swap;

			// by swapping the member of two objects
			// the two objects are effectively swapped
			swap(first.mSize, second.mSize);
			swap(first.mArray, second.mArray);
		}

		// copy-and-swap idiom

		// note that parameter argument is taken by value(so, this can also work as move assignment operator)
		dumb_array& operator=(dumb_array other)
		{
			swap(*this, other);
			return *this;
		}

		// move constructor
		// a move constructor should not generally throw(although, it can, it shouldn't),
		// that's why noexcept
		dumb_array(dumb_array&& other) noexcept
			: dumb_array() // initialize via default constructor(C++11)
			{
				swap(*this, other);
			}

	private:
		std::size_t mSize;
		int* mArray;
};


// new int[size](), makes the elements default initialized(because of the use of '()')
