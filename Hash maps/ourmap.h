#include<string>
using namespace std;
template <typename V>
class MapNode
{
public:
  string key;
  V value;
  MapNode *next;

  MapNode(string key, V value)
  {
    this->key = key;
    this->value = value;
    next = NULL;
  }

  ~MapNode() {
    delete next;
  }
};

template <typename V>
class ourmap {
  MapNode<V> **buckets;
  int count;
  int numBuckets;

  ourmap() {
    count = 0;
    numBuckets = 5;
    buckets = new MapNode<V> *[buckets];

    for (int  i = 0; i < numBuckets; i++)
    {
      buckets[i] = NULL;
    }
  }

  int size() {
    return count;
  }

  V getValue(string key) {
    int bucketIndex = getHashCode(key);
    MapNode<int> *head = buckets[bucketIndex];

    while(head != NULL) {
      if(head -> key == key) {
        return head->value;
      }
      head = head->next;
    }
    return 0;
  }

  private:
  int getHashCode(string key) {
    int hashCode = 0;
    int currentCoeffecient = 1;

    for (int i = key.size() - 1; i >= 0;i--) {
      hashCode += key[i] * currentCoeffecient;
      hashCode %= numBuckets;
      currentCoeffecient *= 37;
      currentCoeffecient %= numBuckets;

    }

    return hashCode % numBuckets;
  }

  public:
  void insert(string key,V value) {
    int bucketIndex = getHashCode(key);
    MapNode<int> *head = buckets[bucketIndex];
    while(head != NULL) {
      if (head->key == key) {
        head->value = value;
        return;
      }
      head = head->next;
    }
    head = buckets[bucketIndex];
    MapNode<int> *node = new MapNode<>(key, value);
    node->next = head;
    buckets[bucketIndex] = node;
    count++;
  }

  V remove(string key) {
    int bucketIndex = getHashCode(key);
    MapNode<int> *head = buckets[bucketIndex];
    MapNode<int> *prev = NULL;
    while(head!=NULL) {
      if(head->key == key) {
        if (prev == NULL) {
          buckets[bucketIndex] = head->next;
        }
        else
        {
          prev->next = head ->next
        }
        V value = head->value;
        delete head;
        count--;
        return value;
      }
      prev = head;
      head = head->next
    }

    return 0;
  }

  ~ourmap() {
    for (int  i = 0; i < numBuckets; i++) {
      delete buckets[i];
    }

    delete[] buckets;
  }
};