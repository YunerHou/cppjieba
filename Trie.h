#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <fstream>
//#include <ext/hash_map>
#include <map>
#include <cstring>
#include <stdint.h>
#include <cmath>
#include <limits>
#include "cppcommon/str_functs.h"
#include "cppcommon/vec_functs.h"
#include "cppcommon/file_functs.h"
#include "cppcommon/logger.h"
#include "globals.h"


namespace CppJieba
{
    using namespace CPPCOMMON;
    using namespace std;
    //using __gnu_cxx::hash_map;
	typedef map<ChUnicode, struct TrieNode*> TrieNodeMap;

	struct TrieNodeInfo
	{
		string word;
		unsigned int count;
		string tag;
		double weight;
		TrieNodeInfo():word(),count(0),tag(),weight(0.0)
		{
		}
	};

	struct TrieNode
    {
        TrieNodeMap hmap;
        bool isLeaf;
		unsigned int nodeInfoVecPos;

        TrieNode()
        :hmap(), isLeaf(false), nodeInfoVecPos(0)
        {
        }
    };

    class Trie
    {
        private:
            TrieNode* _root;
			vector<TrieNodeInfo> _nodeInfoVec;

			int64_t _totalCount;
			double _minWeight;

        public:
            typedef vector<TrieNodeInfo>::iterator iterator;

        public:
            iterator begin();
            iterator end();

        public:
            Trie();
            ~Trie();
            bool init(const char* const filePath);
            bool destroy();
            void display();

		public:
			const TrieNodeInfo* find(const string& uniStr);
			const TrieNodeInfo* find(const ChUnicode* const chUniStr, size_t len);
			//int findMaxMatch(const ChUnicode* chUniStr, size_t len);

		public:
			double getWeight(const ChUnicode* uniStr, size_t len);
			double getWeight(const string& uniStr);

        private:
			bool _buildTree(const char* const filePath);
			bool _countWeight();
            bool _destroyNode(TrieNode* node);
            void _display(TrieNode* node, int level);
			bool _insert(const TrieNodeInfo& nodeInfo);

		private:
			enum {bufSize = 1024};
    };
}

#endif
