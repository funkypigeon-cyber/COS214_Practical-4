# Rochaan — Decorator

Put your files here:
- TaskDecorator.h                 (abstract decorator, implements WorkComponent)
- SafetyAuditDecorator.h / .cpp
- WeatherDelayDecorator.h / .cpp
- CostOverrunDecorator.h / .cpp
- RushPriorityDecorator.h / .cpp

Depends on: src/shared/WorkComponent.h (a decorator wraps a WorkComponent
and is itself still a WorkComponent).
