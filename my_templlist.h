#pragma once
#include <string>
template<typename T> struct TListenKnoten
{
	T data;
	TListenKnoten<T> *next;
	TListenKnoten<T> *prev;
};

template <typename T>
void vorne_anfuegen(TListenKnoten<T>*& anker, T wert)
{
	TListenKnoten<T> *neuer_eintrag = new TListenKnoten<T>;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		neuer_eintrag->next = anker;
		anker = neuer_eintrag;
	}
}

template <typename T>
void in_liste_einfuegen(TListenKnoten<T>*& anker, T wert_neu, T vor_wert)
{
	TListenKnoten<T> *neuer_eintrag = new TListenKnoten<T>;
	neuer_eintrag->data = wert_neu;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		TListenKnoten<T> *ptr = anker;
		while (ptr->next != nullptr)
		{
			if (ptr->data != vor_wert)
			{
				ptr = ptr->next;
			}
			else
				break;
		}
		if (ptr->next == nullptr && ptr->data != vor_wert)
		{
			ptr->next = neuer_eintrag;
			neuer_eintrag->prev = ptr;
		}
		else
		{
			neuer_eintrag->next = ptr;
			neuer_eintrag->prev = ptr->prev;
			ptr->prev = neuer_eintrag;
			if (neuer_eintrag->prev != nullptr)
				neuer_eintrag->prev->next = neuer_eintrag;
			else
				anker = neuer_eintrag;
		}
	}
}

template<typename T>
void hinten_anfuegen(TListenKnoten<T>*& anker, T wert)
{
	TListenKnoten<T> *neuer_eintrag = new TListenKnoten<T>;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		TListenKnoten<T> *ptr = anker;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = neuer_eintrag;
		neuer_eintrag->prev = ptr;
	}
}

template <typename T>
void liste_loeschen(TListenKnoten<T>*& anker)
{
	TListenKnoten<T> *ptr = anker;
	if (ptr != nullptr)
	{
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
			delete ptr->prev;
		}
		delete ptr;
		anker = nullptr;
	}
}

template <typename T>
std::string liste_als_string(TListenKnoten<T>* anker)
{
	std::string resultat = "";
	if (anker == nullptr)
		return resultat;
	else
	{
		resultat += "[ ";
		TListenKnoten<T> *ptr = anker;
		do
		{
			resultat += std::to_string(ptr->data);
			if (ptr->next != nullptr) resultat += " , ";
			else resultat += " ";
			ptr = ptr->next;
		} while (ptr != nullptr);
		resultat += "]";
	}
	return resultat;
}

template <typename T>
void liste_ausgeben(TListenKnoten<T>* anker)
{
	if (liste_als_string(anker) == "")	//für denn fall, das da leere Liste stehen sollte, nicht eindeutig
		std::cout << "Leere Liste." << std::endl;
	else
		std::cout << liste_als_string(anker) << std::endl;
}


template <typename T>
T add(const T var_a, const T var_b)
{
	return var_a + var_b;
}

template <typename T>
T liste_aufaddieren(TListenKnoten<T>* anker)
{
	TListenKnoten<T> *ptr = anker;
	T ergebnis = 0;
	while (ptr != nullptr)
	{
		ergebnis = add(ergebnis, ptr->data);
		ptr = ptr->next;
	}
	std::cout << "Listensumme " << ergebnis << std::endl;
	return ergebnis;
}
