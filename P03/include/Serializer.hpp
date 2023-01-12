//
// Created by Jan Duchscherer on 26.12.22.
//

#ifndef P02_INCLUDE_SERIALIZER_HPP_
#define P02_INCLUDE_SERIALIZER_HPP_

class IKomponente;

class Serializer {
  private:
    IKomponente const& ik;
  public:
    Serializer(IKomponente const& root);
    void writeToJson(const char* fname);
    ~Serializer() = default;
};

#endif //P02_INCLUDE_SERIALIZER_HPP_
