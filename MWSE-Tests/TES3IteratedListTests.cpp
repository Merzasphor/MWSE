#include "pch.h"
#include "CppUnitTest.h"

#define MWSE_NO_CUSTOM_ALLOC 1
#include "..\MWSE\TES3IteratedList.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomContainers {
	TEST_CLASS(IteratedList) {
	public:

		//
		// Insertion tests
		//

		TEST_METHOD(InsertAtIterator) {
			TES3::IteratedList<int> list;
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
			TES3::IteratedList<int> list;
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
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 10; i++) {
				list.push_front(rand());
			}

			list.push_front(9001);
			Assert::AreEqual(9001, list.front());
		}

		TEST_METHOD(PushBack) {
			TES3::IteratedList<int> list;
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
			TES3::IteratedList<int> list;
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
			TES3::IteratedList<int> list;
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

		TEST_METHOD(CachedIteration) {
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 10; i++) {
				list.push_front(rand() % 1000);
			}

			// Calculate the sum twice.
			int sum = 0;
			const auto ittBefore1 = list.current;
			for (list.cached_begin(); list.current; list.cached_next()) {
				// On 3rd element, calculate the sum again...
				if (list.current == list.head->next->next) {
					const auto ittBefore2 = list.current;
					for (list.cached_begin(); list.current; list.cached_next()) {
						sum += list.current->data;
					}
					list.current = ittBefore2;
				}

				sum += list.current->data;
			}
			list.current = ittBefore1;

			const int accumulatedSum = std::accumulate(list.begin(), list.end(), 0);

			Assert::AreEqual(accumulatedSum * 2, sum);
		}

		TEST_METHOD(StandardForLoop) {
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 10; i++) {
				list.push_front(3);
			}

			size_t elements = 0;
			size_t sum = 0;
			for (auto& value : list) {
				elements++;
				sum += value;
			}

			Assert::AreEqual(list.size(), elements);
			Assert::AreEqual(list.size() * 3, sum);
		}

		TEST_METHOD(ReverseForLoop) {
			TES3::IteratedList<int> list;
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
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 10; i++) {
				list.push_front(5);
			}

			unsigned int sum = std::accumulate(list.begin(), list.end(), 0);
			Assert::AreEqual(list.size() * 5, sum);
		}

		TEST_METHOD(AccumulateConstant) {
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 10; i++) {
				list.push_front(5);
			}

			unsigned int sum = std::accumulate(list.cbegin(), list.cend(), 0);
			Assert::AreEqual(list.size() * 5, sum);
		}

		TEST_METHOD(AccumulateReversed) {
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 10; i++) {
				list.push_front(5);
			}

			unsigned int sum = std::accumulate(list.rbegin(), list.rend(), 0);
			Assert::AreEqual(list.size() * 5, sum);
		}

		/*
		// TODO: Figure out why this fails to compile.
		TEST_METHOD(AccumulateConstantReversed) {
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 10; i++) {
				list.push_front(5);
			}

			// Causes compiler errors that need to be figured out...
			unsigned int sum = std::accumulate(list.crbegin(), list.crend(), 0);
			Assert::AreEqual(list.size() * 5, sum);
		}
		*/

		//
		// Lua test functions.
		//

		static void lua_log(sol::this_state ts, sol::object object) {
			sol::state_view state = ts;
			std::string result = state["tostring"](object);
			result += "\n";
			Logger::WriteMessage(result.c_str());
		}

		TEST_METHOD(LuaLength) {
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 10; i++) {
				list.push_back(rand());
			}

			sol::state lua;
			lua.open_libraries();

			try {
				lua["container"] = &list;
				size_t length = lua.safe_script("return #container");
				Assert::AreEqual(list.size(), length);
			}
			catch (std::exception& e) {
				std::wstringstream ss;
				ss << "Lua exception: " << e.what();
				Assert::Fail(ss.str().c_str());
			}
		}

		TEST_METHOD(LuaIPairs) {
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 3; i++) {
				list.push_back(5);
			}

			sol::state lua;
			lua.open_libraries();

			try {
				lua["container"] = &list;
				size_t sum = lua.safe_script(R"(
					local sum = 0
					for _, value in ipairs(container) do
						sum = sum + value
					end
					return sum
					)");
				Assert::AreEqual(list.size() * 5, sum);
			}
			catch (std::exception& e) {
				std::wstringstream ss;
				ss << "Lua exception: " << e.what();
				Assert::Fail(ss.str().c_str());
			}
		}

		TEST_METHOD(LuaPairs) {
			TES3::IteratedList<int> list;
			for (auto i = 0; i < 3; i++) {
				list.push_back(5);
			}

			sol::state lua;
			lua.open_libraries();
			lua["print"] = &lua_log;
			lua["container"] = &list;

			try {
				size_t sum = lua.safe_script(R"(
					local sum = 0
					for _, value in pairs(container) do
						sum = sum + value
						print(string.format("Value: %d; Sum: %d", value, sum))
					end
					return sum
					)");
				Assert::AreEqual(list.size() * 5, sum);
			}
			catch (std::exception& e) {
				std::wstringstream ss;
				ss << "Lua exception: " << e.what();
				Assert::Fail(ss.str().c_str());
			}
		}

	};
}
