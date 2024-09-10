cmake_minimum_required(VERSION 3.25)
project(OLVP)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "-fno-stack-protector")
SET(CMAKE_CXX_FLAGS -pthread)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)


add_executable(OLVP main.cpp
        DataSource/dataLoader.hpp
        DataSource/DataFileDicts.hpp
        common.h
        DataSource/TpchPageSource.hpp
        DataSource/SchemaManager.hpp
        Connector/ConnectorPageSource.hpp
        DataSource/CSVTableReader.hpp
        Page/DataPage.hpp
        Operators/TaskOutputOperator.hpp
        Operators/ProjectOperator.hpp
        Operators/Operator.hpp
        Pipeline/PhysicalPipeline.hpp
        Operators/TableScanOperator.hpp
        Connector/ConnectorId.hpp
        Split/Split.hpp
        Split/ConnectorSplit.hpp
        Connector/ConnectorPageSourceProvider.hpp
        Session/Session.hpp
        Connector/PageSourceManager.hpp
        Connector/SystemPageSourceProvider.hpp
        Connector/ConnectorTableHandle.hpp
        Connector/TpchTableHandle.hpp
        Split/SystemSplit.hpp
        Split/TpchSplit.hpp
        Utils/ArrowRecordBatchViewer.hpp
        Nodes/Node/Node.h
        Nodes/Node/Expression/Expression.h
        Nodes/Node/Expression/Literal.h
        Nodes/Node/Expression/Literals/DoubleLiteral.hpp
        Nodes/Node/Expression/Literals/Int32Literal.hpp
        Nodes/Node/Expression/Literals/Int64Literal.hpp
        Nodes/Node/Expression/Literals/StringLiteral.hpp
        Nodes/Node/Expression/FunctionCall.hpp
        Nodes/Node/AstNodeVisitor.hpp
        Nodes/Node/Expression/Literals/Literals.h
        Nodes/Node/AstNodeViewer.hpp
        Nodes/Node/AstNodeVisit.hpp
        ProjectorAndFilter/ExprAstProjector.hpp
        ProjectorAndFilter/ExprAstProjectorComplier.hpp
        Nodes/Node/Expression/Identifier.hpp
        Nodes/Node/Expression/Column.hpp
        Utils/ArrowDicts.hpp
        Nodes/Node/ExprOuput.hpp
        Descriptor/ProjectDescriptor.hpp
        ProjectorAndFilter/ExprAstFilterComplier.hpp
        ProjectorAndFilter/ExprAstFilter.hpp
        Operators/FilterOperator.hpp
        Descriptor/FilterDescriptor.hpp
        Descriptor/FieldDesc.hpp
        ProjectorAndFilter/ArrowExprNode.hpp
        Operators/SortOperator.hpp Page/Channel.hpp
        Utils/ArrowArrayBuilder.hpp
        Operators/TopKOperator.hpp
        Operators/PartialAggregationOperator.hpp
        Descriptor/AggregateDescriptor.hpp
        Descriptor/AggregationDescriptor.hpp
        Utils/ArrowFunctionOptionsSupplier.hpp
        Operators/Join/LookupSource.hpp
        Operators/Join/LookupSourceFactory.hpp
        Operators/Join/LookupSourceProvider.hpp
        Operators/Join/JoinBridge.hpp
        Operators/Join/PartitionedLookUpSourceFactory.hpp
        Operators/LookupJoinOperator.hpp
        Page/DataPageBuilder.hpp
        Operators/Join/HashTableLookupSource/JoinHash.hpp
        Operators/Join/HashTableLookupSource/PagesHash.hpp
        Operators/Join/HashTableLookupSource/PagesIndex.hpp
        Operators/Join/LookupSourceSupplier.hpp
        Operators/Join/HashTableLookupSource/JoinHashSupplier.hpp
        Operators/Join/HashTableLookupSource/PagesHashStrategy.hpp
        Operators/Join/HashTableLookupSource/SimplePagesHashStrategy.hpp
        Utils/TypeUtils.hpp
        Utils/HashCommon.hpp
        Operators/Join/HashTableLookupSource/PositionLinks.hpp
        Operators/Join/HashTableLookupSource/ArrayPositionLinks.hpp
        Operators/Join/TrackingLookupSourceSupplier.hpp
        Operators/Join/PartitionedLookupSource.hpp
        Operators/Join/JoinProbe.hpp
        Operators/Join/LookupJoinPageBuilder.hpp
        Operators/HashBuilderOperator.hpp
        Operators/FinalAggregationOperator.hpp
        Utils/BlockQueue.hpp
        Operators/LocalExchange/LocalExchange.hpp
        Operators/LocalExchange/LocalExchanger.hpp
        Operators/LocalExchange/LocalExchangeSource.hpp
        Operators/LocalExchange/LocalExchangeSink.hpp
        Operators/LocalExchange/ArbitaryExchanger.hpp
        Operators/LocalExchangeSourceOperator.hpp
        Operators/LocalExchangeSinkOperator.hpp
        Operators/LogicalOperators/LogicalOperator.hpp
        Operators/LogicalOperators/Logical_LocalExchangeSinkOperator.hpp
        Operators/LogicalOperators/Logical_LocalExchangeSourceOperator.hpp
        Operators/LogicalOperators/Logical_LookupJoinOperator.hpp
        Operators/LogicalOperators/Logical_ProjectOperator.hpp
        Operators/LogicalOperators/Logical_SortOperator.hpp
        Operators/LogicalOperators/Logical_TaskOutputOperator.hpp
        Operators/LogicalOperators/Logical_TableScanOperator.hpp
        Operators/LogicalOperators/Logical_TopKOperator.hpp
        Operators/LogicalOperators/Logical_FilterOperator.hpp
        Operators/LogicalOperators/Logical_FinalAggregationOperator.hpp
        Operators/LogicalOperators/Logical_HashBuilderOperator.hpp
        Operators/LogicalOperators/Logical_PartialAggregationOperator.hpp
        Operators/LogicalOperators/PhysicalPipelineCreater.hpp
        Nodes/Node/AstNodePtr.hpp Nodes/Node/AstTreeCleaner.hpp
        Nodes/PlanNode/PlanNode.hpp Nodes/PlanNode/PlanNodeId.hpp
        Nodes/PlanNode/ProjectNode.hpp Nodes/PlanNode/RemoteSourceNode.hpp
        Nodes/PlanNode/TableScanNode.hpp Nodes/PlanNode/TopKNode.hpp
        Nodes/PlanNode/ExchangeNode.hpp Nodes/PlanNode/FilterNode.hpp
        Nodes/PlanNode/FinalAggregationNode.hpp Nodes/PlanNode/LookupJoinNode.hpp
        Nodes/PlanNode/LocalExchangeNode.hpp Nodes/PlanNode/TaskOutputNode.hpp
        Nodes/PlanNode/PartialAggregationNode.hpp Nodes/PlanNode/SortNode.hpp
        Nodes/PlanNode/NodeVisitor.hpp Nodes/PlanNode/PlanNodeTree.hpp
        Descriptor/LookupJoinDescriptor.hpp Descriptor/TopKDescriptor.hpp
        Descriptor/SortDescriptor.hpp Nodes/Node/Serial/NodeTreeSerialization.hpp
        Nodes/Node/Serial/NodeTreeDeserialization.hpp Nodes/PlanNode/Serial/PlanNodeTreeSerialization.hpp
        Nodes/PlanNode/Serial/PlanNodeTreeDeserialization.hpp
        Web/Restful/base64.hpp Web/Restful/Client.hpp Utils/UUID.hpp Web/Restful/Server.hpp Config/WebConfig.hpp
        Execution/Task/TaskManager.hpp Execution/Task/Id/TaskId.hpp
        Execution/Task/Id/StageExecutionId.hpp Execution/Task/Id/StageId.hpp
        Execution/Task/Id/QueryId.hpp Execution/Task/TaskInfo.hpp
        Execution/Task/TasksRuntimeStats.hpp Execution/Buffer/OutputBufferInfo.hpp
        Execution/Task/TaskStatus.hpp Connector/ConnectorPartitioningHandle.hpp
        Partitioning/PartitioningHandle.hpp Partitioning/Partitioning.hpp
        Partitioning/PartitioningHandleSerializer.hpp Partitioning/PartitioningScheme.hpp
        Planner/Fragment.hpp Nodes/PlanNode/PlanNodePtr.hpp Nodes/PlanNode/PlanNodeTreeCleaner.hpp
        Planner/Fragmenter.hpp Planner/PlanTreeAnalyzer.hpp Nodes/PlanNode/PlanNodeTreeViewer.hpp Planner/LocalPlanner/LocalPlanTreeAnalyzer.hpp
        Planner/LocalPlanner/LogicalPipelineFactory.hpp
        Operators/LogicalOperators/LogicalOperators.h Operators/LogicalOperators/Logical_RemoteSourceOperator.hpp
        Operators/RemoteSourceOperator.hpp Execution/Buffer/OutputBuffer.hpp Execution/Buffer/OutputBufferSchema.hpp
        Execution/Task/SqlTaskExecution.hpp Execution/StateMachine.hpp Execution/Task/TaskStateMachine.hpp
        Execution/Task/Context/TaskContext.cpp Execution/Task/TaskExecutor/TaskExecutor.hpp
        Execution/Task/SqlTaskExecutionFactory.hpp Planner/LocalPlanner/PipelineId.hpp
        Execution/Task/SqlTask.hpp Execution/Task/TaskHandle.hpp Execution/Task/SplitRunner.hpp
        Execution/Task/LogicalPipelineRunner.hpp Execution/Task/ScheduledSplit.hpp
        Execution/Task/TaskExecutor/TaskExecutorRunner.hpp Execution/Task/TaskResource.hpp Execution/Task/TaskSource.hpp
        Split/RemoteSplit.hpp Split/WebLocation.hpp Split/Serial/SplitSerial.hpp
        Descriptor/TaskUpdateRequest.hpp Descriptor/TaskInterfere/TaskInterfereRequest.hpp
        System/System.hpp Web/TaskServerInferface.hpp System/TaskServer.hpp
        Web/ArrowRPC/ArrowRPCServer.hpp Execution/Buffer/ClientBuffer.hpp
        Utils/ConcurrentQueue/blockingconcurrentqueue.h Utils/ConcurrentQueue/concurrentqueue.h Utils/ConcurrentQueue/lightweightsemaphore.h
        Execution/Buffer/SimpleOutputBuffer.hpp Execution/Buffer/BroadcastOutputBuffer.hpp
        Execution/Buffer/LazyOutputBuffer.hpp Execution/Buffer/BroadcastOutputBufferManager.hpp
        Execution/Buffer/OutputBufferManager.hpp Execution/Buffer/SimpleOutputBufferManager.hpp Execution/Task/RemoteTask.hpp
        Descriptor/TaskInterfere/TaskIntraParaUpdateRequest.hpp Descriptor/TaskBufferOpRequest.hpp
        NodeCluster/Node.hpp Execution/Scheduler/SqlStageExecution.hpp
        Execution/Scheduler/SqlStageExecutionStateMachine.hpp Execution/Task/RemoteTaskFactory.hpp
        Execution/Scheduler/StageLinkage.hpp Execution/Scheduler/StageScheduler.hpp Execution/Scheduler/StageExecutionAndScheduler.hpp
        Execution/Scheduler/NormalStageScheduler.hpp NodeCluster/NodeSelector.hpp Execution/Scheduler/SourcePartitionedScheduler.hpp
        Execution/Scheduler/StageTreeExecutionFactory.hpp Split/SplitSourceFactory.hpp Partitioning/NodePartitioningManager.hpp
        Partitioning/NodePartitionMap.hpp Execution/Scheduler/SqlQueryScheduler.hpp Execution/Scheduler/SqlQueryExecution.hpp
        Query/QueryManager.hpp Web/ArrowRPC/RPCClient.hpp Web/ArrowRPC/DataPageRPCBuffer.hpp
        Web/ArrowRPC/ArrowRPCClient.hpp Web/ArrowRPC/PageTransformer.hpp Execution/Task/Context/DriverContext.cpp
        Execution/Task/Context/PipelineContext.cpp Execution/Task/Context/DriverContext.h
        Execution/Task/Context/PipelineContext.h Execution/Task/Context/TaskContext.h
        Execution/Task/Context/QueryContext.h Execution/Task/Context/QueryContext.cpp Utils/Random.hpp
        Execution/Task/Fetcher/TaskInfoFetcher.hpp Execution/Task/Fetcher/TaskResultFetcher.hpp
        Descriptor/TaskInterfere/TaskInterfereRequestSerial.hpp Execution/Task/TaskInfos/PipelineDescriptor.hpp
        Execution/Task/TaskInfos/TaskInfoDescriptor.hpp Execution/Scheduler/QueryInfos/StageInfo.hpp
        Nodes/PlanNode/PlanNodeTreeToString.hpp Web/QueryInterface.hpp System/QueryServer.hpp
        Descriptor/TaskInterfere/TaskBufferOperatingRequest.hpp Execution/Buffer/OutputPartitioningBuffer/BufferShuffler/HashShuffler.hpp
        Execution/Buffer/OutputPartitioningBuffer/BufferShuffler/HashGenerator.hpp
        Execution/Buffer/OutputPartitioningBuffer/BufferShuffler/SimplePageHashGenerator.hpp
        Execution/Buffer/OutputPartitioningBuffer/OutputPartitioningBuffer.hpp
        Execution/Buffer/OutputPartitioningBuffer/PartitionCount_BufferMap.hpp
        Execution/Buffer/OutputPartitioningBuffer/TaskBufferGroup.hpp Execution/Buffer/OutputPartitioningBufferManager.hpp
        Utils/FileCommon.hpp Execution/Task/Context/TableScanRecord.hpp
        Partitioning/SystemPartitioningHandle.h Partitioning/SystemPartitioningHandle.cpp
        NodeCluster/NodesManager.h NodeCluster/NodesManager.cpp Query/QueryStateMachine.hpp
        Nodes/PlanNode/PlanNodeTreeToJson.hpp
        TpchTest/Tools/TableViewer.hpp
        TpchTest/Tools/CSVTableFormatChecker.hpp
        TpchTest/Querys/Query1.hpp
        Nodes/Node/Expression/Literals/Date32Literal.hpp Nodes/Node/Expression/Literals/DayTimeIntervalLiteral.hpp
        Utils/TimeCommon.hpp Descriptor/TableScanDescriptor.hpp Config/ExecutionConfig.hpp Utils/RW_BlockQueue.hpp
        DataSource/CSVCacheableTableReader.hpp DataSource/CSVOnceTableReader.hpp TpchTest/Querys/Query2.hpp
        TpchTest/Querys/Query3.hpp TpchTest/Querys/Query4.hpp TpchTest/Querys/Query5.hpp TpchTest/Querys/Query6.hpp
        TpchTest/Querys/Query7.hpp Nodes/Node/Expression/IfExpression.hpp TpchTest/Querys/Query8.hpp
        TpchTest/Querys/Query9.hpp TpchTest/Querys/Query10.hpp Operators/Join/NestedLoopJoin/NestedLoopJoinBridge.hpp
        Operators/Join/NestedLoopJoin/NestedLoopJoinPagesSupplier.hpp Operators/NestedLoopBuildOperator.hpp
        Operators/NestedLoopJoinOperator.hpp Nodes/PlanNode/CrossJoinNode.hpp Nodes/PlanNode/CrossJoinNode.hpp Descriptor/CrossJoinDescriptor.hpp
        Operators/LogicalOperators/Logical_NestedLoopJoinOperator.hpp Operators/LogicalOperators/Logical_NestedLoopBuildOperator.hpp
        TpchTest/Querys/Query11.hpp Nodes/Node/Expression/InExpression.hpp TpchTest/Querys/Query12.hpp
        TpchTest/Querys/Query2_hash.hpp
        TpchTest/Querys/Query3_hash.hpp
        Execution/Buffer/OutputPartitioningBuffer/BufferShuffler/ShuffleExecutor.hpp
        Execution/Buffer/OutputPartitioningBuffer/PartitionResultCache.hpp
        TpchTest/Querys/Query4_hash.hpp
        TpchTest/Querys/Query5_hash.hpp
        TpchTest/Querys/Query7_hash.hpp
        TpchTest/Querys/Query8_hash.hpp
        TpchTest/Querys/Query9_hash.hpp
        TpchTest/Querys/Query10_hash.hpp
        TpchTest/Querys/Query11_hash.hpp
        TpchTest/Querys/Query12_hash.hpp
        Operators/LimitOperator.hpp
        Operators/LogicalOperators/Logical_LimitOperator.hpp
        Nodes/PlanNode/LimitNode.hpp
        TpchTest/Querys/Query9_hashtest.hpp
        TpchTest/Querys/Query8_ShuffleStage.hpp
        Execution/Buffer/OutputPartitioningBuffer/ShuffleStageBuffer.hpp
        Execution/Buffer/ShuffleStageBufferManager.hpp
        Execution/Buffer/SimpleShuffleStageBuffer.hpp
        Execution/Buffer/SimpleShuffleStageBufferManager.hpp
        TpchTest/Querys/Query12_ShuffleStage.hpp
        TpchTest/Querys/Query11_ShuffleStage.hpp
        TpchTest/Querys/Query10_ShuffleStage.hpp
        TpchTest/Querys/Query7_ShuffleStage.hpp
        TpchTest/Querys/Query5_ShuffleStage.hpp
        TpchTest/Querys/Query4_ShuffleStage.hpp
        TpchTest/Querys/Query2_ShuffleStage.hpp
        TpchTest/Querys/Query3_ShuffleStage.hpp
        Execution/Task/Context/TaskThroughputInfo.h
        Query/RegQuery.h
        Utils/Timer.hpp
        Script/ScriptParser.hpp
        Script/ScriptExecutor.hpp
        Script/Instruction.hpp
        Script/InstructionInterpreter.hpp
        Script/SimpleLexer.hpp
        Script/SimpleToken.hpp
        Script/SimpleParser.hpp
        Script/Script.hpp
        Script/InstructionExecutor.hpp
        Script/ScriptExecutionContext.hpp
        Script/ScriptQueryMonitor.hpp
        Session/SessionRepresentation.hpp
        Session/RuntimeConfigParser.hpp
        System/ClusterServer.h
        System/ClusterServer.cpp
        NodeCluster/Heartbeat.hpp
        Web/ClusterInterface.hpp
        System/TaskServer.h
        System/TaskServer.cpp
        Utils/ThreadPool.h
        Utils/ThreadPool.cpp
        Utils/WebCommon.hpp
        TpchTest/Querys/Query10_2.hpp
        TpchTest/Querys/Query2Join.hpp
        Config/NodeTypeConfig.hpp
        TpchTest/Querys/Query2SJoin.hpp
        TpchTest/Querys/Query1_NL.hpp
        TpchTest/Querys/Query2_NL.hpp
        TpchTest/Querys/Query3_NL.hpp
        TpchTest/Querys/Query4_NL.hpp
        TpchTest/Querys/Query5_NL.hpp
        TpchTest/Querys/Query6_NL.hpp
        TpchTest/Querys/Query7_NL.hpp
        TpchTest/Querys/Query8_NL.hpp
        TpchTest/Querys/Query9_NL.hpp
        TpchTest/Querys/Query10_NL.hpp
        TpchTest/Querys/Query11_NL.hpp
        TpchTest/Querys/Query12_NL.hpp
        TpchTest/Querys/Query2_hash_NL.hpp
        TpchTest/Querys/Query3_hash_NL.hpp
        TpchTest/Querys/Query4_hash_NL.hpp
        TpchTest/Querys/Query5_hash_NL.hpp
        TpchTest/Querys/Query7_hash_NL.hpp
        TpchTest/Querys/Query8_hash_NL.hpp
        TpchTest/Querys/Query9_hash_NL.hpp
        TpchTest/Querys/Query10_hash_NL.hpp
        TpchTest/Querys/Query11_hash_NL.hpp
        TpchTest/Querys/Query12_hash_NL.hpp
        TpchTest/Querys/Query2Join_NL.hpp
        TpchTest/Querys/Query2JoinShuffleStage.hpp
        TpchTest/Querys/Query1_single.hpp
        TpchTest/Querys/Query2_single.hpp
        TpchTest/Querys/Query3_single.hpp
        TpchTest/Querys/Query4_single.hpp
        TpchTest/Querys/Query5_single.hpp
        TpchTest/Querys/Query6_single.hpp
        TpchTest/Querys/Query7_single.hpp
        TpchTest/Querys/Query8_single.hpp
        TpchTest/Querys/Query9_single.hpp
        TpchTest/Querys/Query10_single.hpp
        TpchTest/Querys/Query11_single.hpp
        TpchTest/Querys/Query12_single.hpp
        TpchTest/Querys/Query2Join_single.hpp
        TpchTest/Querys/Query1_ssingle.hpp
        TpchTest/Querys/Query2JoinTwoShuffleStage.hpp
        TpchTest/Querys/Query2Join2TwoShuffleStage.hpp
        TpchTest/Querys/Query2Join2ShuffleStage.hpp
        Operators/LocalExchange/HashExchanger.hpp
        TpchTest/Querys/Query2JoinMulHashBuild.hpp
        TpchTest/Querys/Query4_NL_MulHashBuild.hpp
        TpchTest/Querys/SimpleTest/Query_SupplierJoinSupplier.hpp

        Utils/SafeMap.hpp
        Execution/Event/SimpleEvent.hpp
        Execution/Event/Event.h
        Shell/Shell.hpp
        Execution/Task/Statistics/CPU/CpuInfo.hpp
        Execution/Task/Statistics/CPU/ThreadInfo.hpp
        Execution/Task/Statistics/CPU/CpuInfoReader.hpp
        Execution/Task/Statistics/CPU/ThreadInfoReader.hpp
        Execution/Task/Statistics/CPU/TaskCpuUsageDescriptor.hpp
        Execution/Task/Statistics/NIC/NetInfoCollector.hpp
        Utils/TextColor.h
        Prediction/PPM.hpp
        Execution/Buffer/BufferInfoDescriptor.hpp
        Prediction/ClusterContext.hpp
        Utils/StringUtils.hpp
        Web/HttpServer/mongoose.h
        Web/HttpServer/mongoose.c
        Web/HttpServer/HttpServer.h
        TpchTest/Querys/Query2Join_NL_SmallOrders.hpp
        TpchTest/Querys/Query2Join_NL_SmallOrders_ProbeShuffle.hpp
        Execution/Task/TaskInfos/JoinInfoDescriptor.hpp
)



include_directories(
        "/home/zxk/open-codes/json/include/"
        "/usr/local/include/"
        "/usr/local/include/restclient-cpp"
        "/home/zxk/.local/include"
        "/home/zxk/open-codes/oneapi-tbb-2021.9.0/include"

)

target_link_libraries(
        OLVP
        pistache
        /usr/local/lib64/libpistache.so
        /usr/local/lib/librestclient-cpp.so
        curl
        arrow
        arrow_acero
        arrow_flight
        gandiva
        /home/zxk/open-codes/oneapi-tbb-2021.9.0/lib/intel64/gcc4.8/libtbb.so
)
