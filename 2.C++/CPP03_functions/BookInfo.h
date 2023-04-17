//#pragma once
#ifndef BOOK_INFO_H
#define BOOK_INFO_H
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<istream>

/*За програма за менажиране на книгите в библиотека, дефинирайте клас BookInfo с private член данни следната
● ISBN (International Standard Book Number)
● Заглавие
● Номер на издание
● Автор(и)
● Жанр(ове)
● Потребителски рейтинг-число от 0 до 5
.. (каквото друго е необходимо в следващите задачи)
*/

class BookCollection;

class BookInfo
{
private:
	std::string m_ISBN;
	std::string m_title;
	std::vector<std::string> m_author;
	std::vector<std::string> m_genre;
	int m_edition; 
	double m_readerRating;
	int m_readerRatingVotesCount;
	std::vector<BookCollection*> m_bookCollectionContainer;

public:
	BookInfo();

	BookInfo( const std::string& m_ISBN
			, const std::string& m_title
			, int m_edition
			, const std::vector<std::string>& m_author
			, const std::vector<std::string>& m_genre
			, double m_readerRating
			, const std::vector<BookCollection*>& m_bookCollectionContainer);

	//----- getters-----
	//	 std::string& getISBN()  {	return this->ISBN; }   BookInfo ddddd.getISBN().clear()

	const std::string& getISBN() const;

	const std::string& getTitle() const;

	int getEdition() const;

	const std::vector<std::string>& getAuthor() const;

	const std::vector<std::string>& getGenre() const;

	int getReaderRating() const;

	//----- setters----
	void updateReaderRating(int inputReaderRating);

	void serialize() 
	{
	
	}
	void deserialize()
	{

	}


};




#endif // !BOOKSTOREINFO_H
