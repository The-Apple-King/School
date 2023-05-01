#ifndef HANDLER_H_
#define HANDLER_H_

#include <string>
#include "IEntity.h"
#include "Robot.h"
#include "Drone.h"
#include "IStrategy.h"
#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "SpinDecorator.h"

/**
 * @brief Handler class interface to allow creation of new handlers.
 * 
 */
class Handler{
    public:
        /**
         * @brief Construct a new Handler object
         * 
         */
        Handler(){
            next_handler = nullptr;
        }

        /**
         * @brief Function to handle the request that is passed.
         * 
         * @param drone The drone requesting the delivery
         * @param scheduler The list of available robots to assign to the delivery
         */
        virtual void handle_request(std::vector<Drone*> drones, std::vector<IEntity*> scheduler) = 0;
        
        /**
         * @brief Set the next handler object
         * 
         * @param handler The next handler in the chain of responsibility
         */
        virtual void set_next_handler(Handler* handler) {next_handler = handler; };

        /**
         * @brief Set the data needed to make drones move
         * 
         */
        void setTrip(Drone* drone);

       
    private:
        Handler* next_handler;

};

#endif
