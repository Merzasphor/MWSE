#pragma once

namespace TES3 {

	template <typename K, typename V>
	struct HashMap {
		struct KeyValuePair {
			K key; // 0x0
			V value; // 0x0 + sizeof(K)
		};
		struct Node {
			// Allow convenient access to the key/value.
			union {
				KeyValuePair keyValuePair; // 0x0
				struct {
					K key; // 0x0
					V value; // 0x0 + sizeof(K)
				};
			};
			Node* nextNode; // 0x0 + sizeof(K) + sizeof(V)
		};
		struct VirtualTable {
			void(__thiscall* destructor)(HashMap<K, V>*, bool); // 0x0
			unsigned int(__thiscall* hashKey)(HashMap<K, V>*, K); // 0x4
			bool(__thiscall* compareKey)(HashMap<K, V>*, K, K); // 0x8
			void(__thiscall* makeKeyValuePair)(HashMap<K, V>*, KeyValuePair*, K, V); // 0xC
			void(__thiscall* deleteKeyValuePair)(HashMap<K, V>*, KeyValuePair*); // 0x10
		};
		VirtualTable* vTable; // 0x0
		size_t count; // 0x4
		size_t bucketCount; // 0x8
		Node** buckets; // 0xC

		unsigned int hashKey(K& key) { return vTable->hashKey(this, key); }
		bool compareKey(K& first, K& second) { return vTable->compareKey(this, first, second); }
		bool makeKeyValuePair(KeyValuePair* kvp, K& key, V& value) { vTable->makeKeyValuePair(this, kvp, key, value); }
		bool deleteKeyValuePair(KeyValuePair* kvp) { vTable->deleteKeyValuePair(this, kvp); }

		bool containsKey(K& key) {
			auto index = hashKey(key);
			for (auto itt = buckets[index]; itt; itt = itt->nextNode) {
				if (compareKey(key, itt->kvp.key)) {
					return true;
				}
			}
			return false;
		}

		V& getValue(K& key) {
			auto index = hashKey(key);
			for (auto itt = buckets[index]; itt; itt = itt->nextNode) {
				if (compareKey(key, itt->kvp.key)) {
					return itt->kvp.value;
				}
			}
			throw std::runtime_error("Value doesn't exist for given key.");
		}
	};
	static_assert(sizeof(HashMap<const char*, void*>) == 0x10, "TES3::HashMap failed size validation");
}
