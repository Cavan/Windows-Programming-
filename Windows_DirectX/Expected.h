/* FILE: Expected.h
 * PROJECT: Windows and DirectX programming
 * PROGRAMMER: Cavan Biggs
 * FIRST VERSION: December 22nd 2018
 * DESCRIPTION: This file contains a method for handling errors, and described on the website
				https://bell0bytes.eu/expected/ as an alternative to just throwing the C++ default exceptions
				which have been shown to use a large amount of resources, the method below is a way to combat this problem.
 *
 *
 *
 *
 *
*/


#ifndef EXPECTED
#define EXPECTED

template<class T>
class Expected
{
protected:
	union
	{
		T result;
		std::exception_ptr spam;
	};
	bool gotResult;
	Expected() {};

public:
	//constructors and destructor 
	Expected(const T& r) : result(r), gotResult(true) {};
	Expected(T&& r) : result(std::move(r)), gotResult(true) {};
	Expected(const Expected& e) : gotResult(e.gotResult) {}
	Expected(Expected&& e) : gotResult(e.gotResult) {}
	~Expected() {};

	void swap(Expected& e){ }

	// Creating expect from exceptions
	template<class E>
	static Expectedf<T> fromException(const E& exception) {}

	static Expected<T> fromException(std::exception_ptr p) {}
	static Expected<T> fromException() {}


	//operator overload
	Expected& operator=(const Expected& e) {}

	//getters
	bool isValid() const { return gotResult; }
	bool wasSuccessful() const { return gotResult; }
	T& get()
	{
		if (!gotResult)
			std::rethrow_exception(spam);
		return result;
	}
	const T& get const{}

	// probe for exception
	template<class E>
	bool hasException() const {}

};
















#endif // !EXPECTED
