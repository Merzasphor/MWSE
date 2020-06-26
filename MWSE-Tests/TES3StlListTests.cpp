#include "pch.h"
#include "CppUnitTest.h"

#define MWSE_NO_CUSTOM_ALLOC 1
#include "..\MWSE\TES3StlList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomContainers {
	TEST_CLASS(StlList) {
public:

	//
	// Insertion tests
	//

	TEST_METHOD(InsertAtIterator) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_back(rand());
		}

		list.insert(list.begin(), 2);
		Assert::AreEqual(2, list.front());

		list.insert(list.end(), 4);
		Assert::AreEqual(4, list.back());

		list.insert(++list.begin(), 6);
		Assert::AreEqual(6, list[1]);
	}

	TEST_METHOD(InsertAtPosition) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(rand());
		}

		list.insert(0, 2);
		Assert::AreEqual(2, list.front());

		list.insert(1, 2);
		Assert::AreEqual(2, *(list.begin() + 1));

		list.insert(list.size(), 4);
		Assert::AreEqual(4, list.back());

		list.insert(1, 6);
		Assert::AreEqual(6, list[1]);
	}

	TEST_METHOD(PushFront) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(rand());
		}

		list.push_front(9001);
		Assert::AreEqual(9001, list.front());
	}

	TEST_METHOD(PushBack) {
		TES3::StlList<int> list;
		list.push_back(42);
		Assert::AreEqual(42, list.back());

		for (auto i = 0; i < 10; i++) {
			list.push_front(rand());
		}

		list.push_back(9001);
		Assert::AreEqual(9001, list.back());
	}

	//
	// Erasure tests
	//

	TEST_METHOD(EraseAtIterator) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(rand() % 1000);
		}
		const int sumBefore = std::accumulate(list.begin(), list.end(), 0);

		list.insert(list.begin() + 4, 999);
		list.erase(list.begin() + 4);

		const int sumAfter = std::accumulate(list.begin(), list.end(), 0);
		Assert::AreEqual(sumBefore, sumAfter);
	}

	TEST_METHOD(EraseAtPosition) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(rand() % 1000);
		}
		const int sumBefore = std::accumulate(list.begin(), list.end(), 0);

		list.insert(4, 999);
		list.erase(4);

		const int sumAfter = std::accumulate(list.begin(), list.end(), 0);
		Assert::AreEqual(sumBefore, sumAfter);
	}

	//
	// Other access tests
	//

	TEST_METHOD(StandardForLoop) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(rand() % 1000);
		}

		auto sentinel = list.sentinel();

		size_t elements = 0;
		for (auto& value : list) {
			elements++;
		}

		Assert::AreEqual(list.size(), elements);
	}

	TEST_METHOD(ReverseForLoop) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(rand() % 1000);
		}

		size_t elements = 0;
		for (auto it = list.rbegin(); it != list.rend(); ++it) {
			elements++;
		}

		Assert::AreEqual(list.size(), elements);
	}

	TEST_METHOD(Accumulate) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(5);
		}

		unsigned int sum = std::accumulate(list.begin(), list.end(), 0);
		Assert::AreEqual(list.size() * 5, sum);
	}

	TEST_METHOD(AccumulateConstant) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(5);
		}

		unsigned int sum = std::accumulate(list.cbegin(), list.cend(), 0);
		Assert::AreEqual(list.size() * 5, sum);
	}

	TEST_METHOD(AccumulateReversed) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(5);
		}

		unsigned int sum = std::accumulate(list.rbegin(), list.rend(), 0);
		Assert::AreEqual(list.size() * 5, sum);
	}

	TEST_METHOD(AccumulateConstantReversed) {
		TES3::StlList<int> list;
		for (auto i = 0; i < 10; i++) {
			list.push_front(5);
		}

		// Causes compiler errors that need to be figured out...
		//unsigned int sum = std::accumulate(list.crbegin(), list.crend(), 0);
		//Assert::AreEqual(list.size() * 5, sum);
		Assert::Fail(L"Compiler says no.");
	}

	};
}
