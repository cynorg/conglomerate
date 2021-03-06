# Conglomerate: Work In Progress!
Conglomerate aims to be the go-to template for starting a new watch project for the Pebble smartwatch.

It will consist of a repository of GPL/BSD/CC utilities, libraries, and resources which can be forked and modified to accelerate the creation of a stable and optimal Pebble project, where all you need to code are the unique pieces you need.

The primary goals of the project:
  - [x] free/open source licensing/permissions for all included functionality
    - [ ] core is MIT, libraries are separated by license type
  - [ ] Optimized libraries to implement the common features desired in a Pebble watch app, targeting but not limited to:
    - [ ] Connection state ( & optional tracking via AM )
    - [ ] Battery state ( & optional tracking via AM )
    - [?] AppMessage (w/ retry queues on watch and phone side) - <em>([BAM](http://github.com/smallstoneapps/bam) ?)</em>
    - [ ] Configuration page generation
    - [ ] Settings saving/loading/transferring between watch, phone, and settings page
    - [ ] Timezone
    - [ ] Vibration & custom vibration patterns
    - [ ] Weather
      - [ ] multiple weather sources
      - [ ] phone GPS and manual location entry
    - [ ] Magnetometer state
    - [ ] Accelerometer data tracking
  - [ ] Minimal generated code footprint for each platform functionality
    - [ ] Compatibility with Overlay technique <em>(specific implementation deferring until ready for 3.0)</em>
