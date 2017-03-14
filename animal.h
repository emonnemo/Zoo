#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <set>

using namespace std;
/** @class Animal
  * Kelas Animal
  */
class Animal {
  public:
    Animal();
    /**
      * \brief Constructor
      * \details Menciptakan email
      * \param _ID id jenis animal
      * \param _id nomor pada jenisnya
      * \param _legend penanda hewan pada peta
      * \param _weight berat badan* \param _eat persentase makan 0-100%
      * \param _type karnivor, herbivor, omnivor
      * \param _position posisi hewan
      */
    Animal(string _id,
           int _number,
           char _legend,
           float _weight,
           float _eat,
           char _type,
           pair<int,int> _position);

    /** @brief Destructor.
      */
    virtual ~Animal();

    /** @brief Copy Constructor
      * \details copy constructor menjamin tidak bitwise copy.
      * @param a Animal yang ingin di-copy
      */
    Animal(const Animal& a);

    /** @brief Operator =
      * \details operator sama dengan, menjamin tidak bitwise copy
      * @param a Animal yang ingin di-copy
      */
    Animal& operator=(const Animal& a); 

    /**
      * \brief GetID
      * \details Mengembalikan id hewan
      * \return string
      */
    string GetId() const;

    /**
      * \brief Getid
      * \details Mengembalikan nomor number di hewan tersebut
      * \return int
      */
    int GetNumber() const;

    /** @brief GetWeight
      * \details mengembalikan nilai weight dari suatu Animal
      */
    float GetWeight() const;

    /**
      * \brief GetFood
      * \details mengembalikan nilai persentase makanan animal
      * \return eat
      */
    float GetEat() const;

    /** @brief GetPos
      * \details mengembalikan nilai posisi dari suatu Animal
      */
    pair<int,int> GetPos() const;

    /** @brief GetType
      * \details mengembalikan type dari suatu Animal
      */
    char GetType() const;

    /**
      * \brief GetLegend
      * \details mengembalikan legenda suatu Animal
      * \return legenda Animal tersebut
      */
    char GetLegend() const;

    /**
     * \brief GetHabitat
     * \details mengembalikan habitat
     * \return habitat
     */
    set<char> GetHabitat() const;

    /** @brief SetWeight
      * \details mengatur berat badan suatu Animal
      * @param _weight nilai berat badan yang ingin  di tetapkan untuk suatu Animal
      */
    void SetWeight(float _weight);

    /** @brief SetPos
      * \details mengatur posisi suatu Animal
      * @param _position nilai posisi yang ingin  di tetapkan untuk suatu Animal
      */
    void SetPos(pair<int,int> _position);

    /**
     * \brief GetCompatible
     * \details mengembalikan set compatible
     * \return compatible
     */
    set<string> GetCompatible() const;

    virtual void Act() const = 0;

    /**
    * \brief Interact
    * \details mengoutput hasil interaksi dengan Animal
    */
    virtual void Interact() const = 0;

    /**
    * \brief Description
    * \details mengoutput deskripsi Animal tersebut
    * \param a jenis binatang
    */
    void Description(string a) const;

    /**
      * \brief Move
      * \details Berpindah sejauh 1 langkah ke arah sesuai direction
      * \I.S.: arah untuk direction sudah pasti masih dalam cage
      * \param direction 0 ke atas, 1 ke kiri, 2 ke kanan, 3 ke bawah
      */
    void Move(int direction);

    protected:
      string id;
      int number;
      char legend;
      float weight;
      float eat;
      char type;
      pair<int,int> position;
      set<string> compatible;
      set<char> habitat;
};

#endif
