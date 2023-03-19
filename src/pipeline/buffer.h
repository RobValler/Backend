/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "IComponent.h"

#include <queue>
#include <mutex>

template<class T>
class CPipelineBuffer : public IComponent
{
public:
    CPipelineBuffer() =default;
    ~CPipelineBuffer() =default;

    bool Init() override { return true; }
    bool Start() override  { return true; }
    bool Process() override  { return true; }
    bool Stop() override  { return true; }

    bool Read(std::shared_ptr<void>) override { return false; }
    bool Write(const std::shared_ptr<void>) override { return false; }

    bool Read(T& data) {
        const std::lock_guard<std::mutex> lock(m_bufferLock);

        if(!m_buffer.empty()) {
            data = m_buffer.front();
            m_buffer.pop();
            return true;
        } else {
            return false;
        }
    }

    void Write(const T& data) {
        const std::lock_guard<std::mutex> lock(m_bufferLock);
        m_buffer.push(data);
    }

private:
    std::queue<T> m_buffer;
    std::mutex m_bufferLock;

};

