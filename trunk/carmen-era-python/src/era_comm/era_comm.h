#ifndef ERA_COMM_H
#define ERA_COMM_H

class EraComm
{
public:
  virtual ~EraComm();
  static EraComm & instance();
  double time();
  const char * host();
  void listen( double seconds );
private:
  EraComm();
  EraComm( const EraComm & );
  EraComm & operator=( const EraComm & );

  static EraComm * _instance;
};

#endif /*ERA_COMM_H*/
