#pragma once
#include <memory>

#include <RubiksCubeBackendInterface.h>
#include <RubiksCubeListBackend.h>
#include <RubiksCubePhyBackend.h>

enum BackendType {
    LIST,
    PHYSICAL
};

class RubiksCubeBackendFactory {
    
public:
    std::unique_ptr<RubiksCubeBackendInterface> getBackend(const BackendType &type) {
        // TODO: Add case for physical backend
        return std::unique_ptr<RubiksCubeBackendInterface>(new RubiksCubeListBackend());
        
    }
};