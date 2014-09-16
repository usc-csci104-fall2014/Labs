#ifndef DATA_H_
#define DATA_H_

#include <string>
#include <exception>
#include <iostream>

// extra activity: switching debug messages on / off
#ifdef DEBUG
  #define DEBUG_MSG(x) std::cout << (x) << std::endl;
#else
  #define DEBUG_MSG(x)
#endif

namespace lab4
{
	struct not_impl_exception: std::exception
	{
		const char* what() const noexcept
		{
			return "Not Implemented";
		}
	};

	struct out_of_bound: std::exception
	{
		const char* what() const noexcept
		{
			return "Index out of bound";
		}
	};

	struct DataS
	{
		std::string print() const;
		DataS();
	};

	class DataC
	{
		// operator overloads here
		friend std::ostream & operator<<(???);
		friend DataC operator+(const ?? & lhs, const ?? & rhs);
		
	private:
		std::string * _data;
		
	public:
		// Constructors
		DataC();    // default
		DataC(???); // make new DataC with string
		DataC(???); // copy a DataC class
		
		// destructor
		~DataC();
		
		// other member functions
		DataC & operator=(const DataC & rhs);
		void setString(const std::string & s) { *_data = s; } // the least exciting function
	};
} // namespace lab4

#endif // DATA_H_
