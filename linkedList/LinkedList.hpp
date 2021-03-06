/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return m_size;	//returns length of linked list of size m_size
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
    Node<T>* temp = m_front;

	if(temp == nullptr)
	{
		return false;
	}
	else
	{
		while(1)
		{
			if(temp->getValue() == value)
				{
					return true;
				}
				else
				{
					if(temp->getNext() == nullptr)
						return false;
					else
						temp = temp->getNext();
				}
		}

	}
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	Node<T>* temp = m_front;
	    /** TODO
	        Fix this method
	    */
	    if (this->isEmpty())
	    {
	        return false;
	    }
	    else
	    {
	        while(1)
	        {
	            if(m_size == 1)
	            {
	                delete m_front;
	                m_size--;
	                m_front = nullptr;
	                return true;
	            }
	            else if(temp->getNext() != nullptr)
	            {
	                secondintoLast = temp;
	                temp = temp->getNext();
	            }
	            else
	            {
	                lastNode = temp;
	                temp = nullptr;
	                delete lastNode;
	                secondintoLast->setNext(nullptr);
	                m_size--;
									return true;
	            }
	        }
	    }
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
