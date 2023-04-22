#include "BookInfo.h"


BookInfo::BookInfo() :m_edition(0), m_readerRating(0) {};

BookInfo::BookInfo(
	  const std::string& m_ISBN
	, const std::string& m_title
	, int m_edition
	, const std::vector<std::string>& m_author
	, const std::vector<std::string>& m_genre
	, double m_readerRating
	, const std::vector<BookCollection*>& m_bookCollectionContainer)
	: m_ISBN(m_ISBN)
	, m_title(m_title)
	, m_edition(m_edition)
	, m_author(m_author)
	, m_genre(m_genre)
	, m_readerRating(m_readerRating)
	, m_bookCollectionContainer(m_bookCollectionContainer) {};


const std::string& BookInfo::getISBN() const { return this->m_ISBN; }

const std::string& BookInfo::getTitle() const { return this->m_title; }

int BookInfo::getEdition() const { return this->m_edition; }

const std::vector<std::string>& BookInfo::getAuthor() const { return this->m_author; }

const std::vector<std::string>& BookInfo::getGenre() const { return this->m_genre; }

int BookInfo::getReaderRating() const { return this->m_readerRating; }

void BookInfo::updateReaderRating(int inputReaderRating) {

	this->m_readerRating = (m_readerRating * m_readerRatingVotesCount + inputReaderRating) / (m_readerRatingVotesCount + 1);
	m_readerRatingVotesCount++;
}