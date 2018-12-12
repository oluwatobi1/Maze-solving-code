        /* 
Daileon Algorithm - Labirintos Resolver
    Bred by: Jaspion Lopes de Freitas
    Course: Ciência da Computação
    Institution: Faculty of Pythagoras Votorantim-Sorocaba
    */

    // definitions and variable declarations of the robot code maze resolver;
            
    #define vel_motor_esq 10  // controls left engine speed;
    #define vel_motor_dir 11  //controls right motor speed;
    #define e1 7  // controls the direction of rotation of the left motor;
    #define e2 6  // controls direction of rotation of motor left direction rotation
    #define d1 4  //controls the direction of rotation of the right motor;
    #define d2 5  // controls the direction of rotation of the right motor;
 
    int trigger_frente = A4; //controls the pulse sent from the front sensor
    int echo_frente = A1; // controls the pulse received from the front sensor
    
    int trigger_esq = A3 ;// controls the pulse sent from the front sensor
    int echo_esq = A0;// controls the pulse received from the front sensor
    
    int trigger_dir = A5;// controls the pulse sent from the front sensor
    int echo_dir = A2;// controls the pulse received from the front sensor
    
    // configuration of input types of declared variables;    
    void setup()
    {
        pinMode(trigger_frente, OUTPUT); //arduino signal output from trigger_front
        pinMode(echo_frente, INPUT);// echo_front arduino signal input
        
        pinMode(trigger_esq, OUTPUT);// Arduino signal output from the front trigger
        pinMode(echo_esq, INPUT);// echo front arduino signal input        
        
        pinMode(trigger_dir, OUTPUT);// Arduino signal output from the front trigger
        pinMode(echo_dir, INPUT);// echo_frente arduino signal input  front axle arduino signal input
       
        pinMode(vel_motor_esq, OUTPUT);// arduino signal output from left motor speed
        pinMode(vel_motor_dir, OUTPUT);// arduino signal output from right motor speed
     
        pinMode(e1, OUTPUT);// arduino signal output from the left motor rotation direction control
        pinMode(e2, OUTPUT);// arduino signal output from the left motor rotation direction control
        pinMode(d1, OUTPUT);// arduino signal output from the right motor rotation direction control
        pinMode(d2, OUTPUT);// arduino signal output from the right motor rotation direction control
        delay(5000);
    }
    
    // code in infinite repetition of the project;
    void loop()
    {
     // declaration of variables used to control the project;
     long duracao_frente, duracao_esq, duracao_dir, direita, esquerda, frente; 
     
     
   
     digitalWrite(trigger_frente, LOW);  // é declarada as respectivas entradas e saídas de sinal do
     delayMicroseconds(2);               // sensor ultrassônico e armazenada pela variável do sensor
     digitalWrite(trigger_frente, HIGH); // que converte a velocidade do som que é de 340 m/s ou  
     delayMicroseconds(5);               // 29 microsegundos por centímetro, como o sinal vai e volta
     digitalWrite(trigger_frente, LOW);  // esse tempo é a metade sendo sensor= tempo/29/2 ;
     duracao_frente = pulseIn(echo_frente, HIGH); // assim segue também nos outros dois sensores .
     frente = duracao_frente/29/2;
    

     digitalWrite(trigger_esq, LOW);
     delayMicroseconds(2);
     digitalWrite(trigger_esq, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigger_esq, LOW); 
     duracao_esq = pulseIn(echo_esq, HIGH);
     esquerda = duracao_esq/29/2;
    
     digitalWrite(trigger_dir, LOW);
     delayMicroseconds(2);
     digitalWrite(trigger_dir, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigger_dir, LOW); 
     duracao_dir = pulseIn(echo_dir, HIGH);
     direita = duracao_dir/29/2; 
     
     //analogWrite(vel_motor_esq, 0);  // block to initialize inputs with pulse 0 or off;
     //analogWrite(vel_motor_dir, 0); //
     analogWrite(e1, 0);            //
     analogWrite(e2, 0);            //  
     analogWrite(d1, 0);            //
     analogWrite(d2, 0);            //
     
       if(frente >8) // if there is a free path ahead it follows this logic below:
         {  
           // the use of the four if's below within this if is for the control of the robot's handling,
           // in order to keep it following the right wall straight;
           
           if(direita >7 && direita< 13) // if the distance from the wall to the right is between 9 and 12 cm, the robot
                                         //keeps straight;
             {               
               //analogWrite(vel_motor_esq, 120);
               //analogWrite(vel_motor_dir, 150);
           
               analogWrite(e1, 255);
               analogWrite(e2, 0);
               analogWrite(d1, 0);
               analogWrite(d2, 255);                                                        
             }
         
           if(direita >=13)  // if the distance from the wall to the right is greater than or equal to 13 cm, the robot increases
                             // your left motor speed to approach the right wall;
             {
               //analogWrite(vel_motor_esq, 255);
               //analogWrite(vel_motor_dir, 60);
           
               analogWrite(e1, 255);
               analogWrite(e2, 0);
               analogWrite(d1, 0);
               analogWrite(d2, 255);                               
             }
             
                 
           if(direita <=7)   // if the distance from the wall to the right is less than or equal to 8 cm, the robot increases
                             // your right motor speed to move away from the right wall;
             {
               //analogWrite(vel_motor_esq, 60);
               //analogWrite(vel_motor_dir, 255);
           
        analogWrite(e1, 0);
        analogWrite(e2, 150);
        analogWrite(d1, 0);
        analogWrite(d2, 150);                   
             }
         
         
 //New Edit
                       
                 
          if(esquerda <=5)   // if the distance from the wall to the left is less than or equal to 8 cm, the robot increases
                             // your left motor speed to move away from the right wall;
             {
               //analogWrite(vel_motor_esq, 60);
               //analogWrite(vel_motor_dir, 255);
           
     analogWrite(e1, 150);
        analogWrite(e2, 0);
        analogWrite(d1, 150);
        analogWrite(d2, 0);                    
             }
         }
         



 //End of edit
       if(esquerda <=20 && direita>20 && frente <=8) dir(); //if the forward distance is less than or equal to 8 cm,
                                                            //the distance to the right is greater than 20 cm and the distance
                                                            //the left is less than or equal to 20 cm it calls the dir () function;   
            
       if(esquerda >20 && direita>20 && frente <=8) esq(); //if the forward distance is less than or equal to 8 cm, 
                                                            //the distance to the right is greater than 20 cm and the distance
                                                            //the left is greater than 20 cm it calls the dir () function;
       
       if(direita <=20 && esquerda>20 && frente <=8) esq(); //if the forward distance is less than or equal to 8 cm,
                                                            //the distance to the right is less than or equal to 20 cm and the distance
                                                            //the left is greater than 20 cm it calls the function esq (); 
       
       if(direita<=20 && esquerda<=20 && frente<=8) esq(); //if the forward distance is less than or equal to 8 cm,
                                                            //the distance to the right is less than or equal to 20 cm and the distance
                                                            //the left is less than or equal to 20 cm it calls the back () function;                           
    
    }
       
    void esq() // function to make the robot rotate 90º to the left if there is no front and right exit;
      {
       
        //analogWrite(vel_motor_esq, 120);
        //analogWrite(vel_motor_dir, 120);
           
        analogWrite(e1, 0);
        analogWrite(e2, 150);
        analogWrite(d1, 0);
        analogWrite(d2, 150);
        delay(200);      
        
      }
    
    void dir() // function to make the robot rotate 90º to the right if there is no forward or left exit;
      {
        
      
        //analogWrite(vel_motor_esq, 120);
        //analogWrite(vel_motor_dir, 120);
        
        analogWrite(e1, 150);
        analogWrite(e2, 0);
        analogWrite(d1, 150);
        analogWrite(d2, 0);             
        delay(600);
               
      }
    
    void voltar() //function to make the robot rotate 180º if there is no forward, left and right exit;
      {
       
        //analogWrite(vel_motor_esq, 120);
        //analogWrite(vel_motor_dir, 120);
           
        analogWrite(e1, 150);
        analogWrite(e2, 0);
        analogWrite(d1, 150);
        analogWrite(d2, 0);
        delay(1000); 
         
      }   
  
    
    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
